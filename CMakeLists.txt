cmake_minimum_required(VERSION 3.15)
project(BitwiseWizard VERSION 1.0 LANGUAGES CXX)

# Padrão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configurações específicas para Windows
if(WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
endif()

# Diretórios de terceiros
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/src/thirdparty/imgui)
set(IMGUI_BACKENDS_DIR ${IMGUI_DIR}/backends)
set(STB_IMAGE_SOURCE ${CMAKE_SOURCE_DIR}/src/thirdparty/stb_image.h)

# Dependências
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Fontes principais do projeto
set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/app_gui.cpp
    ${CMAKE_SOURCE_DIR}/src/core/functions.cpp
)

# Fontes do ImGui
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.cpp
    ${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp
)

# Criar executável
add_executable(BitwiseWizard WIN32
    ${PROJECT_SOURCES}
    ${IMGUI_SOURCES}
)

# Includes
target_include_directories(BitwiseWizard PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${IMGUI_DIR}
    ${IMGUI_BACKENDS_DIR}
)

# Linkagem
target_link_libraries(BitwiseWizard PRIVATE
    glfw
    OpenGL::GL
    $<$<PLATFORM_ID:Windows>:dwmapi.lib gdi32 opengl32>
)

# Copiar pasta de assets (imagens, fontes, etc.) para o diretório de build
if(EXISTS ${CMAKE_SOURCE_DIR}/assets)
    file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
endif()
