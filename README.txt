TRABALHO DE LINGUAGEM DE MONTAGEM

Disciplina: Linguagens de Montagem - Ciência da Computação (2º Ano)
Autores: Thaynara Nascimento e Gabriel Velasquez

=============================================================================
1. APRESENTAÇÃO
=============================================================================

Este projeto foi dividido em 3 subpastas referentes à implementação das 
questões exigidas no material:

- Pasta [Q1_EstudoDirigido]: Contém o arquivo PDF com a resolução teórica 
  das Tarefas 1, 2 e 3.

- Pasta [Q2_NASM]: Contém o arquivo fonte "main_print.nasm" com a resolução 
  em linguagem Assembly para NASM (imprime uma mensagem ao usuário).

- Pasta [Q3_C_Inline]: Contém os arquivos fonte divididos nos quatro incisos:
    I.   a_logica.c: Resolução da equação lógica.
    II.  b_atribuicao.c: Atribuição utilizando deslocamento de bits.
    III. c_manipulacao.c: Manipulação e deslocamento de bits.
    IV.  d_processamento.c: Processamento aritmético de valores.

=============================================================================
2. COMO EXECUTAR (Makefiles e Dependências)
=============================================================================

Para simplificação do processo, foi criado um arquivo Makefile que compila e 
executa os códigos automaticamente.

-----------------------------------------------------------------------------
A) CONFIGURAÇÃO PARA WINDOWS (Via WSL)
-----------------------------------------------------------------------------
Para executar no Windows, é necessário utilizar o WSL (Subsistema do Windows 
para Linux).

1. Abra o Windows PowerShell como Administrador e digite:
   wsl --install

2. Reinicie sua máquina. Ao voltar, crie um usuário e senha para o Linux.

3. Abra o terminal do WSL (Ubuntu) e instale as ferramentas necessárias 
   (GCC, NASM, suporte 32-bits e Make) com o comando:
   
   sudo apt update && sudo apt install build-essential nasm gcc-multilib make

-----------------------------------------------------------------------------
B) CONFIGURAÇÃO PARA LINUX NATIVO
-----------------------------------------------------------------------------
Se estiver usando Linux, verifique se o 'make' está instalado digitando:
   which make

Se não retornar nada, instale as dependências:

- Em Debian/Ubuntu:
  sudo apt install build-essential nasm gcc-multilib make

- Em Arch Linux:
  sudo pacman -S make nasm

=============================================================================
3. COMANDOS DE COMPILAÇÃO
=============================================================================

O Makefile já configura automaticamente as flags de 64 bits (Questão 2) e 
32 bits (Questão 3). Utilize os comandos abaixo no terminal:

- Para compilar e rodar TUDO de uma vez:
  make all

- Para compilar e rodar questões ESPECÍFICAS:
  Questão 2 .......: make q2
  Questão 3 (a) ...: make q3a
  Questão 3 (b) ...: make q3b
  Questão 3 (c) ...: make q3c
  Questão 3 (d) ...: make q3d

- Para limpar arquivos temporários e executáveis:
  make clean

Para mais informações:

=============================================================================
LINK DO REPOSITÓRIO
=============================================================================
https://github.com/thay-jpeg/lm-assembly.git