# 🧙‍♂️ BitwiseWizard

**Um mago das conversões e operações entre bases numéricas... agora com interface estilosa usando Dear ImGui!**

Se você já quis somar dois números em hexadecimal, dividir binários, ou só mostrar que sabe o que é complemento de dois, esse é o seu grimório digital!

## ✨ O que é isso?

O **BitwiseWizard** é uma aplicação C++ mágica que:
- Converte números entre binário, octal, decimal e hexadecimal 🌀
- Suporta ponto flutuante e números negativos 🌊
- Permite escolher representações binárias como:
  - Sem sinal (unsigned)
  - Sinal magnitude
  - Complemento de 1
  - Complemento de 2
- Faz operações aritméticas (soma, subtração, multiplicação e divisão) direto entre diferentes bases 🔮

E o melhor: com interface gráfica feita em **Dear ImGui**, pra você conjurar seus cálculos com estilo!

---

## 🧪 Funcionalidades

### 🔄 Conversor de bases
- Detecta automaticamente a base de entrada (`0b` binário, `0` octal, `0x` hexadecimal ou decimal puro)
- Converte para qualquer outra base (2, 8, 10, 16)
- Oferece diferentes representações ao converter para binário

### ➕ Operações entre bases
- Aceita dois números de **qualquer base**
- Realiza a operação e te mostra o resultado na base desejada
- Simplesmente mágico.

### 💻 Interface Gráfica (GUI)
- Desenvolvida com **Dear ImGui**
- Rápida, leve, intuitiva
- Perfeita para estudantes, curiosos, e entusiastas de computação de baixo nível

---

## 🧰 Requisitos

- **C++17 ou superior**
- **Dear ImGui** (você pode usar com SDL2, GLFW ou qualquer binding que preferir)
- Compilador compatível com `g++` ou `clang++`
- CMake (recomendado para organização)

---

## 🚀 Como rodar

1. Clone o repositório:
```bash
git clone https://github.com/Clara-M-Grossl/BitwiseWizard.git
cd BitwiseWizard
```

2. Compile:
Se estiver usando CMake:

```bash
mkdir build
cd build
cmake ..
make
```

3. Rode o feitiço:
```bash
./BitwiseWizard
```

(ou execute o binário gerado pelo seu ambiente preferido)

---

## 🎨 Interface com Dear ImGui

A GUI do BitwiseWizard foi criada com a biblioteca **Dear ImGui**, permitindo uma experiência dinâmica e agradável.

Funcionalidades da interface:
- Seleção de base via botões
- Caixas de texto para entrada dos números
- Resultados visíveis instantaneamente
- Feedback direto sobre erros (ex: divisão por zero)
- Estilo personalizável via temas do ImGui

---

## 📁 Estrutura do Projeto

```
📂 BitwiseWizard/
├── main.cpp              // Menu principal (modo terminal)
├── assets.cpp            // Funções auxiliares (formatação, utilitários)
├── build/                // Diretório de build (gerado após compilação)
├── src/                  // Código-fonte principal
│   ├── gui/              // Interface gráfica com Dear ImGui
│   ├── core/             // Lógica de conversão e operações (back-end)
│   ├── thirdparty/       // Bibliotecas externas (ex: Dear ImGui)
├── build.bat             // Script para compilação no Windows
├── CMakeLists.txt        // Configuração do projeto para o CMake
├── README.md             // Documentação do projeto

```

---

## 🧠 Por que usar?

- Aprender como diferentes sistemas de numeração funcionam
- Visualizar representações binárias com e sem sinal
- Treinar conceitos de ponto flutuante e operações entre bases
- Dar um show no laboratório de arquitetura de computadores 😎

---

## 👨‍💻 Equipe
Clara Marcela Grossl  
E-mail: claramgrossl22@gmail.com  

Luan Gabriel  
E-mail: luangabriel27@icloud.com  

Isadora da Costa Viana  
E-mail: isadoracv@outlook.com  

José Vitor de Lara Miranda  
E-mail: jose.vlm@grad.ufsc.br  

---

## 🪄 Licença

Este projeto é open-source sob a licença MIT. Use, modifique e compartilhe à vontade!

---
