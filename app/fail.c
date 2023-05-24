#include <stdio.h>
int main(void){
    printf("Makefile: \x1b[1;31mERROR: No rule to make target \x1b[1;33m'Compiled'\x1b[1;31m, needed by \x1b[1;33m'Makefile'\x1b[1;31m.  Stop.\x1B[0m\n");
    return 0;
}