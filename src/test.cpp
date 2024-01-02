/**
 * @file test.h
 * @brief just a test source file
 */
#include "test.h"
#include "colors.h"


int sum(int a, int b){
    return a + b;
}

void test(){
    print_color(INVERSE, BLUE, "This is a sum in test!\n");
    int number = sum(1, 1);
    print_color(ITALIC, GREEN, "Result: %d\n", number);
}