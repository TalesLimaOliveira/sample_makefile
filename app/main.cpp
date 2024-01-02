/**
 * @file main.cpp
 * @author Tales Oliveira (g.dev/TalesOliveira)
 */

#include <iostream>
#include <colors.h>
#include <test.h>

int main(void)
{
    char name[] = "World";
    int number = 69;

    print_color(BOLD, RED, "Hello, %s!\nThis is a number: %d!\n", name, number);
    test();
    print_color("This is a default message!\n");

    return 0;
}
