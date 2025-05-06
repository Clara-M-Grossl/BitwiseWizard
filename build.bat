@echo off
:: Definir o diretório de build
set BUILD_DIR=build

:: Criar o diretório de build se ele não existir
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

:: Navegar até o diretório de build
cd %BUILD_DIR%

:: Executar o CMake para gerar os arquivos de construção
cmake ..

:: Construir o projeto
cmake --build . --config Release

:: Verificar se o binário foi gerado e executar
if exist BitwiseWizard.exe (
    echo "Executando o programa..."
    BitwiseWizard.exe
) else (
    echo "Erro: O binário não foi gerado. Verifique os erros durante a compilação."
)

:: Manter a janela aberta após a execução
pause