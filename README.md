<img src="./cabecalho.png" />

### Trabalho de Linguagem de Montagem

Este repositório contém as implementações referentes ao trabalho da disciplina de Linguagens de Montagem do curso de Ciência da Computação (Unioeste). O projeto explora a linguagem Assembly (NASM) e a integração com a linguagem C (Inline Assembly).

### 📂 Estrutura do Projeto

O projeto está organizado em três diretórios principais:

* **`Q1_EstudoDirigido/`**: Contém o arquivo `.pdf` com a resolução teórica das Tarefas 1, 2 e 3.
* **`Q2_NASM/`**: Contém a resolução da Questão 2 em Assembly puro (NASM), arquivo `main_print.nasm`.
* **`Q3_C_Inline/`**: Contém os códigos em C com Assembly Inline divididos em quatro itens:
    * `a_logica.c`: Resolução da equação lógica.
    * `b_atribuicao.c`: Atribuição com deslocamento de bits (shifts).
    * `c_manipulacao.c`: Manipulação e normalização de bits.
    * `d_processamento.c`: Processamento aritmético de variáveis.

### ⚙️ Pré-requisitos e Configuração

Para garantir a portabilidade e facilidade na compilação, o projeto utiliza um **Makefile**.

#### Ambiente Windows (via WSL)
Recomendamos o uso do **WSL (Windows Subsystem for Linux)** para compilar o projeto em ambiente Windows.

1.  **Instalar o WSL:**
    Abra o PowerShell como administrador e execute:
    ```powershell
    wsl --install
    ```
    *Reinicie o computador após o comando e crie seu usuário/senha Linux quando solicitado.*

2.  **Instalar Dependências:**
    No terminal do WSL (Ubuntu), execute o comando abaixo para instalar o GCC, NASM, Make e bibliotecas de 32 bits:
    ```bash
    sudo apt update && sudo apt install build-essential nasm gcc-multilib make
    ```

#### Ambiente Linux
Se você já estiver no Linux, certifique-se de ter o `make` e as bibliotecas instaladas.

* **Debian/Ubuntu:**
    ```bash
    sudo apt update && sudo apt install build-essential nasm gcc-multilib make
    ```
* **Arch Linux:**
    ```bash
    sudo pacman -S base-devel nasm make
    ```

### 🚀 Compilação e Execução

O arquivo `Makefile` gerencia as flags de compilação necessárias (64 bits para a Questão 2 e 32 bits para a Questão 3).

### Comandos Disponíveis

Para compilar e rodar **todo o projeto** sequencialmente:
```bash
make all
```
Ou apenas:
```bash
make
```

Para compilar e rodar questões **ESPECÍFICAS**:

| Questão | Comando | Descrição |
| :---: | :---: | :---: |
| Questão 2 | make q2 | Executa impressão para o usuário |
| Questão 3 (a) | make q3a | Executa equação lógica |
| Questão 3 (b) | make q3b | Executa resolução de atribuição |
| Questão 3 (c) | make q3c | Executa manipulação e deslocamento de bit |
| Questão 3 (d) | make q3d | Executa processamento aritmético |


Para limpar os arquivos compilados (.o, executáveis):
```bash
make clean
```

### 👥 Autores

Thaynara Nascimento

Gabriel Velasquez

---

*Disciplina de Linguagens de Montagem - Ciência da Computação (2º Ano)*

