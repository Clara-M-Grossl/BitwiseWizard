#ifndef APP_GUI_H
#define APP_GUI_H

#include <string>
#include "../thirdparty/imgui/imgui.h"

// Declaração das funções

// Funções de Textura
bool LoadTexture(const char* path, GLuint* out_texture, ImVec2* out_size);
void ShowBackgroundImage();

// Função da Janela
void ShowMainWindow();
#endif