/**
 * @file main.cpp
 * @author Tales Oliveira (g.dev/TalesOliveira)
 */

#include <iostream>
#include <colors.h>
#include <test.h>

int main(int argc, char const *argv[])
{
    if (argc > 1)
        for (size_t i = 1; i <= argc; i++)
            print_color(BOLD, BLUE, "Hello, %s!\n", argv[i]);
    
    char name[] = "World";
    int number = 42;

    print_color(BOLD, RED, "Hello, %s!\nThis is a number: %d!\n", name, number);
    test();
    print_color("This is a default message!\n");

    return 0;
}
