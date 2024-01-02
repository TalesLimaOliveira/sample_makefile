/**
 * @file colors.cpp
 * @author Tales Oliveira (g.dev/TalesOliveira)
 * @brief  Color for your terminal
 */

#include "colors.h"

void print_color(const char *style_code, const char *color_code, const char *format, ...) {
    va_list args;
    va_start(args, format);

    std::cout << style_code << color_code;

    while (*format) {
        if (*format == '%' && *(format + 1) == 's') {
            const char *str_arg = va_arg(args, const char*);
            std::cout << str_arg;
            format += 2;
        } else if (*format == '%' && *(format + 1) == 'd') {
            int int_arg = va_arg(args, int);
            std::cout << int_arg;
            format += 2;
        } else {
            std::cout << *format;
            ++format;
        }
    }

    va_end(args);

    std::cout << RESET;
}

void print_color(const char *color_code, const char *format, ...) {
    va_list args;
    va_start(args, format);

    std::cout << color_code;

    while (*format) {
        if (*format == '%' && *(format + 1) == 's') {
            const char *str_arg = va_arg(args, const char*);
            std::cout << str_arg;
            format += 2;
        } else if (*format == '%' && *(format + 1) == 'd') {
            int int_arg = va_arg(args, int);
            std::cout << int_arg;
            format += 2;
        } else {
            std::cout << *format;
            ++format;
        }
    }

    va_end(args);

    std::cout << RESET;
}

void print_color(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) == 's') {
            const char *str_arg = va_arg(args, const char*);
            std::cout << str_arg;
            format += 2;
        } else if (*format == '%' && *(format + 1) == 'd') {
            int int_arg = va_arg(args, int);
            std::cout << int_arg;
            format += 2;
        } else {
            std::cout << *format;
            ++format;
        }
    }

    va_end(args);

    std::cout << RESET;
}
