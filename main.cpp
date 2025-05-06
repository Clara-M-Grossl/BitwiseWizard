// INCLUDES
#include <GLFW/glfw3.h>
#include "src/thirdparty/imgui/imgui.h"
#include "src/thirdparty/imgui/backends/imgui_impl_glfw.h"
#include "src/thirdparty/imgui/backends/imgui_impl_opengl3.h"
#include "src/gui/app_gui.h" //INTERFACE GRÁFICA
#include "src/core/functions.hpp" //BACK_END

// FUNÇÃO PRINCIPAL
int main() {
    //Inicializa GLFW
    if (!glfwInit()) {
        return -1;
    }

    //Configura janela GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(1280, 720, "BitwiseWizard", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Ativa vsync

    //Configura ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    //Adiciona a fonte Roboto-Regular 
    io.Fonts->AddFontFromFileTTF("assets/fonts/Roboto-Regular.ttf", 16.0f);
    io.FontDefault = io.Fonts->Fonts.back(); 

    // Configura backends da biblioteca ImGui
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    //Loop principal
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Prepara novo frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Chama sua interface
        ShowMainWindow();

        // Renderiza
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    //Limpeza
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}