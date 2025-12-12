#include "stdio.h"

short int a, b;
int c;

int main() {

    a = 1;
    b = 8;

    printf("Questao 3, exercicio c): \n\n");

asm(

    "movw %1, %%ax;"        // carrega 'a' em AX
            "bsrw %%ax, %%cx;"

            "movw $15, %%bx;"
            "subw %%cx, %%bx;"      // BX = 15 - CX.

            "movw %%bx, %%cx;"
            "shlw %%cl, %%ax;"
            "movzwl %%ax, %%esi;"   // zera ESI e move AX para la
            "shll $16, %%esi;"

            "movw %2, %%bx;"        // carrega 'b' em BX
            "bsrw %%bx, %%cx;"

            "incw %%cx;"
            "movw $0xFFFF, %%dx;"
            "shlw %%cl, %%dx;"


            "orw %%dx, %%bx;"       // máscara em B (OR lógico)

            "movzwl %%bx, %%eax;"   // carrega 'b' processado em EAX
            "orl %%esi, %%eax;"     // junta com 'a' processado
            "movl %%eax, %0;"

            : "=m" (c)              // Saída %0
            : "m" (a), "m" (b)      // Entradas %1, %2
            : "%eax", "%ebx", "%ecx", "%edx", "%esi" // Registradores

);

    printf("Resultado Assembly:\n");
    printf("c = %d\n", c);

    return 0;
}