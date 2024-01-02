#include <iostream>
#include <colors.h>
#include <test.h>

int main(void)
{
    char name[] = "Mundo";
    const char *message = "Esta é uma mensagem sem estilo e cor.\n";
    int number = 42;

    print_color(BOLD, RED, "Hello, %s!\nThis is a number: %d.\n", name, number);
    test();
    print_color(message);
    return 0;
}
