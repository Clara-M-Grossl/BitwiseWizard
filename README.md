# 🧙‍♂️ BitwiseWizard

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#%EF%B8%8F-bitwisewizard)

**Um mago das conversões e operações entre bases numéricas... agora com interface estilosa usando Dear ImGui!**

Se você já quis somar dois números em hexadecimal, dividir binários, ou só mostrar que sabe o que é complemento de dois, esse é o seu grimório digital!

## ✨ O que é isso?

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-o-que-%C3%A9-isso)

O **BitwiseWizard** é uma aplicação C++ mágica que:

- Converte números entre binário, octal, decimal e hexadecimal 🌀
- Suporta ponto flutuante e números negativos 🌊
- Permite escolher representações binárias como:
  - Sem sinal (unsigned)
  - Sinal magnitude
  - Complemento de 1
  - Complemento de 2
- Faz operações aritméticas (soma, subtração, multiplicação e divisão) direto entre diferentes bases 🔮

E o melhor: com interface gráfica feita em **Dear ImGui** , pra você conjurar seus cálculos com estilo!

---

## 🧪 Funcionalidades

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-funcionalidades)

### 🔄 Conversor de bases

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-conversor-de-bases)

- Detecta automaticamente a base de entrada (`0b` binário, `0` octal, `0x` hexadecimal ou decimal puro)
- Converte para qualquer outra base (2, 8, 10, 16)
- Oferece diferentes representações ao converter para binário

### ➕ Operações entre bases

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-opera%C3%A7%C3%B5es-entre-bases)

- Aceita dois números de **qualquer base**
- Realiza a operação e te mostra o resultado na base desejada
- Simplesmente mágico.

### 💻 Interface Gráfica (GUI)

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-interface-gr%C3%A1fica-gui)

- Desenvolvida com **Dear ImGui**
- Rápida, leve, intuitiva
- Perfeita para estudantes, curiosos, e entusiastas de computação de baixo nível

---

## 🧰 Requisitos

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-requisitos)

- **C++17 ou superior**
- **Dear ImGui** (você pode usar com SDL2, GLFW ou qualquer binding que preferir)
- Compilador compatível com `g++` ou `clang++`
- CMake (recomendado para organização)

---

## 🚀 Como rodar

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-como-rodar)

1. Clone o repositório:

```shell
git clone xxxxxxxxx
cd BitwiseWizard
```

2. Compile: Se estiver usando CMake:

```shell
mkdir build
cd build
cmake ..
make
```

3. Rode o feitiço:

```shell
./BitwiseWizard
```

(ou execute o binário gerado pelo seu ambiente preferido)

---

## 🎨 Interface com Dear ImGui

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-interface-com-dear-imgui)

A GUI do BitwiseWizard foi criada com a biblioteca **Dear ImGui** , permitindo uma experiência dinâmica e agradável.

Funcionalidades da interface:

- Seleção de base via botões
- Caixas de texto para entrada dos números
- Resultados visíveis instantaneamente
- Feedback direto sobre erros (ex: divisão por zero)
- Estilo personalizável via temas do ImGui

---

## 📁 Estrutura do Projeto

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-estrutura-do-projeto)

```
📂 BitwiseWizard/
├── src/
│   ├── main.cpp         // Menu principal (terminal)
│   ├── gui.cpp          // Lógica da interface com Dear ImGui
│   ├── functions.cpp    // Funções de conversão e operações
│   ├── functions.hpp
│   └── colors.h         // Estilos do terminal
├── CMakeLists.txt
├── README.md
```

---

## 🧠 Por que usar?

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-por-que-usar)

- Aprender como diferentes sistemas de numeração funcionam
- Visualizar representações binárias com e sem sinal
- Treinar conceitos de ponto flutuante e operações entre bases
- Dar um show no laboratório de arquitetura de computadores 😎

---

## 👨‍💻 Equipe

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-equipe)

Clara Luan Isadora José

---

## 🪄 Licença

[](https://github.com/Clara-M-Grossl/BitwiseWizard?tab=readme-ov-file#-licen%C3%A7a)

Este projeto é open-source sob a licença MIT. Use, modifique e compartilhe à vontade!
