# Compilação Genérica de Arquivos
Este projeto consiste em um Makefile genérico que pode ser utilizado em qualquer sistema operacional para compilar programas em C. Ele oferece uma estrutura de pastas organizada e automatiza o processo de compilação e limpeza dos arquivos binários temporários.

Por [Tales L. Oliveira.](https://github.com/TalesLimaOliveira)

## Requisitos
> GCC (MinGW.org GCC Build-2) - Versão 9.2.0

> GNU Make - Versão 3.82.90

<br>

## Organização das Pastas e Arquivos
A estrutura de pastas e arquivos do projeto é a seguinte:

``` bash
    PROGRAM_FOLDER
    ├── app
    │   ├── myapp1.c
    │   ├── myapp2.c
    │   └── myappN.c
    ├── inc
    │   ├── myinclude1.h
    │   ├── myinclude2.h
    │   └── myincludeN.h
    ├── lib
    │   ├── lib1.a
    │   ├── lib2.a
    │   └── libN.a
    ├── src
    │   ├── mysource1.c
    │   ├── mysource2.c
    │   └── mysourceN.c
    ├── Makefile
    └── README.md
```

<br>

## Compilação e Limpeza de Arquivos

Para compilar e executar o projeto, utilize o seguinte comando:

```go
make APP=<nome_do_app>
```

Substitua **<nome_do_app>** pelo nome do arquivo localizado na pasta app que deseja compilar.

O projeto irá criar as pastas **bin** e **obj** para armazenar os arquivos binários temporários gerados durante a compilação.

O projeto irá remover os arquivos temporários automaticamente.

Mas caso queira forçar a limpeza, utilize este comando:

```go
make clean
```

## Links Adicionais

- Repositório do projeto: https://github.com/TalesLimaOliveira

<br>

Sinta-se à vontade para explorar o código-fonte e adaptar o Makefile de acordo com suas necessidades específicas.

<br>

## Arquivo Makefile

```Makefile
# Variaveis
CC = gcc
APPDIR = app
BINDIR = bin
INCDIR = inc
LIBDIR = lib
OBJDIR = obj
SRCDIR = src
FLAGS = -O3 -Wall
APP ?= fail
NAME = $(APP)

# Encontra todos os arquivos-fonte (.c) dentro do diretório especificado, exceto o arquivo principal
SOURCES := $(filter-out $(SRCDIR)/$(APP).c, $(wildcard $(SRCDIR)/*.c))

# Gera a lista de objetos (.o) a partir dos nomes dos arquivos-fonte
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Encontra todos os arquivos de bibliotecas (.a) no diretório de bibliotecas
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

#Executa o make
all: clean folder exe run

# Criação dos diretórios
folder:
ifeq ($(OS),Windows_NT)
	@ if not exist "$(BINDIR)" mkdir $(BINDIR)
	@ if not exist "$(OBJDIR)" mkdir $(OBJDIR)
else
	@ mkdir -p $(BINDIR) $(OBJDIR)
endif

# Compilação do programa executável
exe: objs
	@ echo Makefile: Compiling
	@ $(CC) $(FLAGS) $(APPDIR)/$(NAME).c $(OBJECTS) -I $(INCDIR) -L $(LIBDIR) $(LIBRARIES) -o $(BINDIR)/$(NAME)
	@ echo Makefile: Compiled Successfully

# Compilação dos objetos
objs: $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	@ $(CC) $(FLAGS) -c $< -I $(INCDIR) -o $@

run:
	@ echo Makefile: Running Program
	@ echo =-=-=-=-=-=-=-=-=-=-=-=-=
	@ $(BINDIR)/$(NAME)
	@ echo =-=-=-=-=-=-=-=-=-=-=-=-=
	@ echo Makefile: Program Ended
	@ $(MAKE) -s clean

# Limpeza dos arquivos
.PHONY: clean

clean:
	@ echo Makefile: Cleaning
ifeq ($(OS),Windows_NT)
	@ if exist "$(BINDIR)" del /q $(BINDIR)
	@ if exist "$(OBJDIR)" del /q $(OBJDIR)
	@ if exist "$(BINDIR)" rmdir $(BINDIR)
	@ if exist "$(OBJDIR)" rmdir $(OBJDIR)
else
	@ rm -rf $(OBJDIR)/* $(BINDIR)/*
	@ rmdir $(OBJDIR) $(BINDIR)
endif
	@ echo Makefile: Cleaned Successfully

```