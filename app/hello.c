#include <stdio.h>
#include <colors.h>
#include <test.h>
int main(void){
    printf("%sHello, world!%s\n", SL_GRN, C_RESET);
    test();
    return 0;
}