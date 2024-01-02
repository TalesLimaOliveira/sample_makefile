/**
 * @file test.h
 * @author Tales Oliveira (g.dev/TalesOliveira)
 * @brief just a test source file
 */

#include "test.h"
#include "colors.h"

int sum(int a, int b){
    return a + b;
}

void test(){
    print_color(ITALIC, BLUE, "This is a sum in test:\n");
    int number = sum(1, 1);
    print_color(GREEN, "Result = %d\n", number);

    print_color(RED_WHITE_BG, "Inverse Text\n");
    print_color(HIDDEN, "Password\n");
}
