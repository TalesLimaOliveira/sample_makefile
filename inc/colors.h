#ifndef COLORS_H
#define COLORS_H

#include <iostream>
#include <stdio.h>
#include <cstdarg>

// Define as cores
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

// Define os estilos
#define DEFAULT "\x1B[0m"
#define BOLD    "\x1B[1m"
#define ITALIC  "\x1B[3m"
#define INVERSE "\x1B[7m"

// Função para imprimir com estilo, cor e mensagem (com suporte a argumentos de comprimento variável)
void print_color(const char *format, ...);

#endif//COLORS_H
