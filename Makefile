# Variáveis de Compilação
NASM = nasm
CC = gcc

# Flags para NASM (Questão 2 - 64 bits)
ASM_FLAGS = -f elf64

# Flags para C (Questão 3 - Exigido 32 bits)
C_FLAGS = -m32 -fno-stack-protector -no-pie

# Comandos Principais
# Se digitar só 'make', compila tudo
all: q2 q3a q3b q3c q3d

# QUESTÃO 2 (NASM Puro)
q2: Q2_NASM/main_print.o
	$(CC) Q2_NASM/main_print.o -o Q2_NASM/exec_q2 -no-pie
	@echo "Executando Questão 2..."
	./Q2_NASM/exec_q2

Q2_NASM/main_print.o: Q2_NASM/main_print.nasm
	$(NASM) $(ASM_FLAGS) $< -o $@

#  QUESTÃO 3 (C + Inline Assembly - 32 bits)

# Q3 - Item A
q3a: Q3_C_Inline/a_logica.c
	$(CC) $(C_FLAGS) $< -o Q3_C_Inline/exec_q3a
	@echo "Executando Q3 (a)..."
	./Q3_C_Inline/exec_q3a

# Q3 - Item B
q3b: Q3_C_Inline/b_atribuicao.c
	$(CC) $(C_FLAGS) $< -o Q3_C_Inline/exec_q3b
	@echo "Executando Q3 (b)..."
	./Q3_C_Inline/exec_q3b

# Q3 - Item C
q3c: Q3_C_Inline/c_manipulacao.c
	$(CC) $(C_FLAGS) $< -o Q3_C_Inline/exec_q3c
	@echo "Executando Q3 (c)..."
	./Q3_C_Inline/exec_q3c

# Q3 - Item D
q3d: Q3_C_Inline/d_processamento.c
	$(CC) $(C_FLAGS) $< -o Q3_C_Inline/exec_q3d
	@echo "Executando Q3 (d)..."
	./Q3_C_Inline/exec_q3d

# Limpeza
clean:
	rm -f Q2_NASM/*.o Q2_NASM/exec_q2
	rm -f Q3_C_Inline/*.o Q3_C_Inline/exec_q3*