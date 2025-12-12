#include "stdio.h"

/*
*   Equação lógica exigida:
*   a ^ ((c | ~b) & a);
*/

int a, b, c, x;

int main() {

    a = 5;
    b = 20;
    c = 8;

    printf("Questao 3, exercicio a): \n\n");
    printf("Entradas:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n\n", c);

    asm(
        "movl %1, %%eax;"
        "notl %%eax;"
        "orl %2, %%eax;"

        "movl %%eax, %%ebx;"
        "andl %3, %%ebx;"    // AND a -> ((c | ~b) & a)

        "movl %%ebx, %%eax;"
        "xorl %3, %%eax;"    // XOR a -> a ^ ((c | ~b) & a)

        "movl %%eax, %0;"    // (x)

        : "=m" (x)          // Saída (%0)
        : "m" (b),          // Entrada (%1)
          "m" (c),          // Entrada (%2)
          "m" (a)           // Entrada (%3)
        : "%eax", "%ebx"
    );

    printf("Resultado Assembly:\n");
    printf("x = %d\n", x);

    return 0;
}