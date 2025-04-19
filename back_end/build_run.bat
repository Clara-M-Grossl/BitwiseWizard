@echo off
echo Compilando...
g++ main.cpp functions.cpp -o bitwisewizard.exe
if %ERRORLEVEL% neq 0 (
    echo Erro na compilação.
    pause
    exit /b
)
echo Executando...
bitwisewizard.exe
pause
