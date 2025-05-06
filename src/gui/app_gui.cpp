#define STB_IMAGE_IMPLEMENTATION
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <GLFW/glfw3.h> 
#include "core/functions.hpp"
#include "gui/app_gui.h"
#include "../thirdparty/stb_image.h"
#include "../thirdparty/imgui/imgui.h"
#include "../thirdparty/imgui/imgui_internal.h"
#include "../thirdparty/imgui/backends/imgui_impl_glfw.h"
#include "../thirdparty/imgui/backends/imgui_impl_opengl3.h"

#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif
#ifndef GL_RGBA
#define GL_RGBA 0x1908
#endif
#ifndef GL_UNSIGNED_BYTE
#define GL_UNSIGNED_BYTE 0x1401
#endif

//COLORS
const ImVec4 CYBER_BLUE = ImVec4(0.35f, 0.50f, 0.65f, 1.0f);
const ImVec4 CYBER_PURPLE = ImVec4(0.45f, 0.40f, 0.55f, 1.0f);
const ImVec4 CYBER_PINK = ImVec4(0.60f, 0.45f, 0.50f, 1.0f);
const ImVec4 DARK_NEON = ImVec4(0.12f, 0.12f, 0.14f, 0.95f);
const ImVec4 TITLE_BLUE =  ImVec4(0.4f, 0.7f, 1.0f, 1.0f);

// Variaveis Globais
namespace {
    std::string inputNum;
    std::string result = "Resultado aparecerá aqui...";
    bool fullscreen = false;
    static char inputBuffer[256] = {0};
    
    //Variaveis de textura
    static bool texture_loaded = false;
    static GLuint background_texture = 0;
    static ImVec2 background_size(0, 0);
}

//Funçõa para carregar textura
bool LoadTexture(const char* path, GLuint* out_texture, ImVec2* out_size) {
    stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    unsigned char* data = stbi_load(path, &width, &height, &channels, 4);
    
    if (!data) {
        std::cerr << "STB_IMAGE ERROR: " << stbi_failure_reason() << std::endl;
        return false;
    }

    glGenTextures(1, out_texture);
    glBindTexture(GL_TEXTURE_2D, *out_texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    stbi_image_free(data);
    *out_size = ImVec2((float)width, (float)height);
    return true;
}

// Função para mostrar a imagem
void ShowBackgroundImage() {
    ImGui::GetIO().FontGlobalScale = 1.8f;
    if (!texture_loaded) {
        texture_loaded = LoadTexture("assets/background.png", &background_texture, &background_size);
        if (!texture_loaded) return;
    }

    if (background_texture != 0) {
        ImVec2 window_pos = ImGui::GetWindowPos();
        ImVec2 window_size = ImGui::GetWindowSize();
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        
        draw_list->AddImage(
            (ImTextureID)(intptr_t)background_texture,
            window_pos,
            ImVec2(window_pos.x + window_size.x, window_pos.y + window_size.y),
            ImVec2(0, 1),
            ImVec2(1, 0),
            IM_COL32(255, 255, 255, 255)
        );

        draw_list->AddRectFilled(
            window_pos,
            ImVec2(window_pos.x + window_size.x, window_pos.y + window_size.y),
            IM_COL32(10, 5, 30, 10)
        );

        // Scanlines effectl
        for (int y = 0; y < window_size.y; y += 4) {
            draw_list->AddLine(
                ImVec2(window_pos.x, window_pos.y + y),
                ImVec2(window_pos.x + window_size.x, window_pos.y + y),
                IM_COL32(0, 255, 255, 20)
            );
        }
    }
}

void ShowMainWindow() {
    // Style setup
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.02f, 0.02f, 0.05f, 0.9f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1f, 0.0f, 0.2f, 0.9f);
    style.Colors[ImGuiCol_TitleBgActive] = CYBER_PURPLE;
    style.Colors[ImGuiCol_Tab] = ImVec4(0.1f, 0.1f, 0.2f, 0.9f);
    style.Colors[ImGuiCol_TabActive] = CYBER_BLUE;
    style.Colors[ImGuiCol_TabHovered] = CYBER_PURPLE;
    style.Colors[ImGuiCol_Button] = ImVec4(0.2f, 0.0f, 0.4f, 0.8f);
    style.Colors[ImGuiCol_ButtonHovered] = CYBER_PINK;
    style.Colors[ImGuiCol_ButtonActive] = CYBER_BLUE;
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1f, 0.05f, 0.2f, 0.8f);
    style.WindowRounding = 5.0f;
    style.FrameRounding = 3.0f;
    style.PopupRounding = 5.0f;
    style.GrabRounding = 2.0f;
    style.TabRounding = 3.0f;

    // Window setup
    if (fullscreen) {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::Begin("BitwiseWizard", nullptr, 
            ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
    } else {
        ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
        ImGui::Begin("BitwiseWizard - Conversor Numérico", nullptr, ImGuiWindowFlags_NoCollapse);
    }

    ShowBackgroundImage();

    if (ImGui::BeginTabBar("MainTabBar")) {
        // Base Conversion Tab
        if (ImGui::BeginTabItem("Conversão de Base")) {
            static char inputNum[256] = "";
            static int outputBase = 10;
            static int binaryFormat = 1;
            static std::string result = "";
            static std::string baseInfo = "Aguardando entrada...";

            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(20, 5, 40, 180));
            ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0, 255, 255, 100));
            ImGui::BeginChild("##BaseConv", ImVec2(0, 0), true, ImGuiWindowFlags_None);
            
            ImGui::TextColored(TITLE_BLUE, "Digite o número com prefixo:");
            ImGui::InputTextWithHint("##InputBase", "Ex: 0b1010, 0755, 0xFF, 123", inputNum, sizeof(inputNum));
            
            std::string numStr(inputNum);
            int base_detected = detectBase(numStr);
            if (strlen(inputNum) > 0) {
                switch (base_detected) {
                    case 2: baseInfo = "Base detectada: Binário (0b)"; break;
                    case 8: baseInfo = "Base detectada: Octal (0)"; break;
                    case 10: baseInfo = "Base detectada: Decimal"; break;
                    case 16: baseInfo = "Base detectada: Hexadecimal (0x)"; break;
                    default: baseInfo = "Base inválida ou não reconhecida!";
                }
            } else {
                baseInfo = "Aguardando entrada...";
            }
            ImGui::TextColored(base_detected == 0 ? CYBER_PINK : CYBER_BLUE, baseInfo.c_str());
            
            ImGui::Spacing();
            ImGui::TextColored(TITLE_BLUE, "Base de saída:");
            ImGui::RadioButton("Binário (2)", &outputBase, 2); ImGui::SameLine();
            ImGui::RadioButton("Octal (8)", &outputBase, 8); ImGui::SameLine();
            ImGui::RadioButton("Decimal (10)", &outputBase, 10); ImGui::SameLine();
            ImGui::RadioButton("Hexadecimal (16)", &outputBase, 16);
            
            if (outputBase == 2) {
                ImGui::Spacing();
                ImGui::TextColored(TITLE_BLUE, "Formato binário:");
                ImGui::RadioButton("Sem sinal", &binaryFormat, 1); ImGui::SameLine();
                ImGui::RadioButton("Sinal magnitude", &binaryFormat, 2); ImGui::SameLine();
                ImGui::RadioButton("Complemento de 1", &binaryFormat, 3); ImGui::SameLine();
                ImGui::RadioButton("Complemento de 2", &binaryFormat, 4);
            }
            
            if (ImGui::Button("Converter", ImVec2(120, 40))) {
                if (base_detected == 0) {
                    result = "Número inválido!";
                } else if (base_detected == outputBase) {
                    result = "Bases iguais: " + numStr;
                } else {
                    if (outputBase == 2) {
                        switch (binaryFormat) {
                            case 1: result = isFloat(numStr, base_detected) ? 
                                     floatdecimalBinary(baseToDecimalfloat(numStr, base_detected)) : 
                                     decimalBinary(baseToDecimal(numStr, base_detected));
                                     break;
                            case 2: result = isFloat(numStr, base_detected) ? 
                                     toSignedMagnitudefloat(baseToDecimalfloat(numStr, base_detected)) : 
                                     toSignedMagnitude(baseToDecimal(numStr, base_detected));
                                     break;
                            case 3: result = isFloat(numStr, base_detected) ? 
                                     toOnesComplementfloat(baseToDecimalfloat(numStr, base_detected)) : 
                                     toOnesComplement(baseToDecimal(numStr, base_detected));
                                     break;
                            case 4: result = isFloat(numStr, base_detected) ? 
                                     toTwosComplementfloat(baseToDecimalfloat(numStr, base_detected)) : 
                                     toTwosComplement(baseToDecimal(numStr, base_detected));
                                     break;
                        }
                    } else if (outputBase == 8) {
                        result = deciToOctal(baseToDecimalfloat(numStr, base_detected));
                    } else if (outputBase == 10) {
                        result = doubletostring(baseToDecimalfloat(numStr, base_detected));
                    } else if (outputBase == 16) {
                        result = deciToHexa(baseToDecimalfloat(numStr, base_detected));
                    }
                }
            }
            
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::TextColored(TITLE_BLUE, "Resultado:");
            ImGui::InputTextMultiline("##ResultBase", (char*)result.c_str(), result.size() + 1, 
            ImVec2(-1, ImGui::GetTextLineHeight() * 3), ImGuiInputTextFlags_ReadOnly);
            
            ImGui::EndChild();
            ImGui::PopStyleColor(2);
            ImGui::EndTabItem();
        }

        // Arithmetic Operations Tab
        if (ImGui::BeginTabItem("Operações Aritméticas")) {
            static char inputNum1[256] = "";
            static char inputNum2[256] = "";
            static int operation = 0;
            static std::string decimalResult = "";
            static std::string formattedResult = "";
            static int outputBase = 10;
            static int binaryFormat = 1;

            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(20, 5, 40, 180));
            ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0, 255, 255, 100));
            ImGui::BeginChild("##ArithOps", ImVec2(0, 0), true, ImGuiWindowFlags_None);
            
            ImGui::TextColored(TITLE_BLUE, "Digite dois números:");
            
            // Input 1
            ImGui::InputTextWithHint("##InputOp1", "Ex: 0b1010, 0755, 0xFF", inputNum1, sizeof(inputNum1));
            std::string num1Str(inputNum1);
            int base1 = detectBase(num1Str);
            ImGui::TextColored(base1 == 0 ? CYBER_PINK : CYBER_BLUE, 
                base1 == 0 ? "Base inválida" : ("Base: " + std::to_string(base1)).c_str());
            
            // Input 2
            ImGui::InputTextWithHint("##InputOp2", "Ex: 0b1010, 0755, 0xFF", inputNum2, sizeof(inputNum2));
            std::string num2Str(inputNum2);
            int base2 = detectBase(num2Str);
            ImGui::TextColored(base2 == 0 ? CYBER_PINK : CYBER_BLUE, 
                base2 == 0 ? "Base inválida" : ("Base: " + std::to_string(base2)).c_str());
            
            // Operations
            ImGui::Spacing();
            ImGui::TextColored(TITLE_BLUE, "Operação:");
            ImGui::RadioButton("Soma##op", &operation, 1); ImGui::SameLine();
            ImGui::RadioButton("Subtração##op", &operation, 2); ImGui::SameLine();
            ImGui::RadioButton("Multiplicação##op", &operation, 3); ImGui::SameLine();
            ImGui::RadioButton("Divisão##op", &operation, 4);

            // Calculate button
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.0f, 0.4f, 0.8f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, CYBER_PINK);
            if (ImGui::Button("Calcular", ImVec2(120, 40))) {
                if (base1 == 0 || base2 == 0) {
                    decimalResult = "Número(s) inválido(s)!";
                    formattedResult = "";
                } else {
                    switch (operation) {
                        case 1: decimalResult = sum(num1Str, num2Str, base1, base2); break;
                        case 2: decimalResult = sub(num1Str, num2Str, base1, base2); break;
                        case 3: decimalResult = mult(num1Str, num2Str, base1, base2); break;
                        case 4: decimalResult = div(num1Str, num2Str, base1, base2); break;
                        default: decimalResult = "Selecione uma operação!";
                    }
                    formattedResult = ""; // Reseta o resultado formatado
                }
            }
            ImGui::PopStyleColor(2);
            
            // Output configuration
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::TextColored(TITLE_BLUE, "Configuração de Saída:");
            ImGui::RadioButton("Binário (2)##out", &outputBase, 2); ImGui::SameLine();
            ImGui::RadioButton("Octal (8)##out", &outputBase, 8); ImGui::SameLine();
            ImGui::RadioButton("Decimal (10)##out", &outputBase, 10); ImGui::SameLine();
            ImGui::RadioButton("Hexadecimal (16)##out", &outputBase, 16);

            if (outputBase == 2) {
                ImGui::Spacing();
                ImGui::TextColored(TITLE_BLUE, "Formato binário:");
                ImGui::RadioButton("Sem sinal##bin", &binaryFormat, 1); ImGui::SameLine();
                ImGui::RadioButton("Sinal magnitude##bin", &binaryFormat, 2); ImGui::SameLine();
                ImGui::RadioButton("Complemento de 1##bin", &binaryFormat, 3); ImGui::SameLine();
                ImGui::RadioButton("Complemento de 2##bin", &binaryFormat, 4);
            }

            // Botão para formatar o resultado
            if (!decimalResult.empty() && decimalResult != "Número(s) inválido(s)!" && decimalResult != "Selecione uma operação!") {
                if (ImGui::Button("Formatar Resultado")) {
                    int base = 10; // Assumindo que o resultado das operações está em decimal  
                    switch (outputBase) {
                        case 2:
                            switch (binaryFormat) {
                                case 1:  if (isFloat(decimalResult, base)){
                                        formattedResult = floatdecimalBinary(baseToDecimalfloat(decimalResult, base));
                                    }else{
                                        formattedResult = decimalBinary(baseToDecimal(decimalResult, base));
                                    }
                                    break;
                                case 2: formattedResult = isFloat(decimalResult, base) ? 
                                         toSignedMagnitudefloat(baseToDecimalfloat(decimalResult, base)) : 
                                         toSignedMagnitude(baseToDecimal(decimalResult, base));
                                         break;
                                case 3: formattedResult = isFloat(decimalResult, base) ? 
                                         toOnesComplementfloat(baseToDecimalfloat(decimalResult, base)) : 
                                         toOnesComplement(baseToDecimal(decimalResult, base));
                                         break;
                                case 4: formattedResult = isFloat(decimalResult, base) ? 
                                         toTwosComplementfloat(baseToDecimalfloat(decimalResult, base)) : 
                                         toTwosComplement(baseToDecimal(decimalResult, base));
                                         break;
                            }
                            break;
                        case 8: formattedResult = deciToOctal(baseToDecimalfloat(decimalResult, base)); break;
                        case 10: formattedResult = decimalResult; break;
                        case 16: formattedResult = deciToHexa(baseToDecimalfloat(decimalResult, base)); break;
                    }
                }
            }

            // Result display
            ImGui::Spacing();
            ImGui::Separator();
            ImGui::TextColored(TITLE_BLUE, "Resultado Decimal:");
            ImGui::InputTextMultiline("##DecimalResult", (char*)decimalResult.c_str(), decimalResult.size() + 1, 
                ImVec2(-1, ImGui::GetTextLineHeight() * 2), ImGuiInputTextFlags_ReadOnly);

            if (!formattedResult.empty()) {
                ImGui::Spacing();
                ImGui::TextColored(TITLE_BLUE, "Resultado Formatado:");
                ImGui::InputTextMultiline("##FormattedResult", (char*)formattedResult.c_str(), formattedResult.size() + 1, 
                    ImVec2(-1, ImGui::GetTextLineHeight() * 2), ImGuiInputTextFlags_ReadOnly);
            }
            
            ImGui::EndChild();
            ImGui::PopStyleColor(2);
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    // Fullscreen toggle
    if (ImGui::Button(fullscreen ? "Sair da Tela Cheia" : "Tela Cheia", ImVec2(150, 30))) {
        fullscreen = !fullscreen;
    }

    // Border effect
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImVec2 window_pos = ImGui::GetWindowPos();
    ImVec2 window_size = ImGui::GetWindowSize();
    draw_list->AddRect(
        window_pos,
        ImVec2(window_pos.x + window_size.x, window_pos.y + window_size.y),
        IM_COL32(0, 255, 255, 80),
        5.0f,
        ImDrawFlags_RoundCornersAll,
        2.0f
    );

    ImGui::End();
}
