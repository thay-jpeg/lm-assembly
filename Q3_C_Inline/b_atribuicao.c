#include <stdio.h>

signed char f = -10;
signed long long int g;

int main() {

    asm(
        "movb f, %%al;"       
        "sall $24, %%eax;"   
        "sarl $24, %%eax;"    
        "movl %%eax, %%edx;"  
        "sarl $31, %%edx;"    
        "movl %%eax, g;"     
        "movl %%edx, g+4;" 
        :                  
        :             
        : "%eax", "%edx", "memory" 
    );

    printf("g: %lld\n", g);

    return 0;
}
