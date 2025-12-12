#include <stdio.h>

short int a = 0xABCD;
short int b = 0x1234;
unsigned char c = 8;
int d = 0;

int main() {
  printf("Original a: 0x%04hX\n", a);
  printf("Original b: 0x%04hX\n", b);
  printf("Original c: %d\n", c);

  __asm__ volatile(
      // variável a
      "movw %0, %%ax;\n"
      "andw $0x7777, %%ax;\n"
      "orw $0x2222, %%ax;\n"
      "movw %%ax, %0;\n"

      // variável b
      "movw %1, %%bx;\n"
      "andw $0x0FFF, %%bx;\n"
      "orw $0x000F, %%bx;\n"
      "movw %%bx, %1;\n"

      "addw %%bx, %%ax;\n" // AX = a + b
      "movswl %%ax, %%eax;\n"

      "movzbl %3, %%edx;\n"

      "bsfl %%edx, %%ecx;\n"

      "sarl %%cl, %%eax;\n"
      "movl %%eax, %2;\n"

      : "+m"(a), "+m"(b), "=m"(d)
      : "m"(c)
      : "eax", "ebx", "ecx", "edx", "cc");

  printf("Processado a: 0x%04hX\n", a);
  printf("Processado b: 0x%04hX\n", b);
  printf("Resultado d: %d\n", d);

  return 0;
}
