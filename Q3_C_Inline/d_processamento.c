#include <stdio.h>

short int a = 0xABCD;     
short int b = 0x1234;     
unsigned char c = 8;       
int d = 0;

int main(void) {
  printf("Original a: 0x%04hX\n", (unsigned short)a);
  printf("Original b: 0x%04hX\n", (unsigned short)b);
  printf("Original c: %u\n", (unsigned)c);

  __asm__ volatile (
      /* --- Processar a ---
      "movw %0, %%ax;\n"             /* carregar a em AX (16 bits) */
      "andw $0xF7F7, %%ax;\n"       
      "orw  $0x2222, %%ax;\n"        
      "movw %%ax, %0;\n"       

      /* --- Processar b ---*/
      "movw %1, %%bx;\n"
      "andw $0x0FFF, %%bx;\n"    
      "orw  $0x000F, %%bx;\n"    
      "movw %%bx, %1;\n"

      /* Soma e extensao de sinal
         AX = a (processado)
         BX = b (processado)
         AX + BX -> AX 
      */
      "addw %%bx, %%ax;\n"            /* AX = AX + BX*/
      "movswl %%ax, %%eax;\n"      


      "movzbl %3, %%edx;\n"     
      "bsfl %%edx, %%ecx;\n"       

      "sarl %%cl, %%eax;\n"           

      "movl %%eax, %2;\n"

      : "+m"(a), "+m"(b), "=m"(d)    
      : "m"(c)                
      : "ax", "bx", "cx", "dx", "cc"
  );

  printf("Processado a: 0x%04hX\n", (unsigned short)a);
  printf("Processado b: 0x%04hX\n", (unsigned short)b);
  printf("Resultado d: %d\n", d);

  return 0;
}
