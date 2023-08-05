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
    │   └── myappN.c
    ├── inc
    │   ├── myinclude1.h
    │   ├── myinclude2.h
    │   └── myincludeN.h
    ├── lib
    │   └── libN.a
	├── res
    │   └── resN.txt
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

Por padrao o **<nome_do_app>** vem **app**.

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
EXTSRC = c
EXTINC = h
APPDIR = app
BINDIR = bin
INCDIR = inc
LIBDIR = lib
OBJDIR = obj
SRCDIR = src
FLAGS = -O3 -Wall -Wextra
ECHO ?=
APP ?= app

# Verificação do nome do aplicativo
ifeq ($(APP),)
$(error No app specified. Use: make APP=<app_name>)
endif

# Encontra todos os arquivos-fonte (.$(EXT)) dentro do diretório especificado, exceto o arquivo principal
SOURCES := $(filter-out $(SRCDIR)/$(APP).$(EXT), $(wildcard $(SRCDIR)/*.$(EXT)))

# Gera a lista de objetos (.o) a partir dos nomes dos arquivos-fonte
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXT), $(OBJDIR)/%.o, $(SOURCES))

# Encontra todos os arquivos de bibliotecas (.a) no diretório de bibliotecas
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

#Executa o make
all: clean folder exe

# Criação dos diretórios
folder:
ifeq ($(OS),Windows_NT)
	@ if not exist "$(BINDIR)" mkdir $(BINDIR)
	@ if not exist "$(OBJDIR)" mkdir $(OBJDIR)
else
	@ if [ -d "$(BINDIR)" ]; then mkdir -p $(BINDIR); fi
	@ if [ -d "$(OBJDIR)" ]; then mkdir -p $(OBJDIR); fi
endif

# Compilação do programa executável
exe: objs
	$(if $(ECHO),@echo Makefile: Compiling)
	@ $(CC) $(FLAGS) $(APPDIR)/$(APP).$(EXT) $(OBJECTS) -I $(INCDIR) -L $(LIBDIR) $(LIBRARIES) -o $(BINDIR)/$(APP)
	$(if $(ECHO),@echo Makefile: Compiled Successfully)
	@ $(MAKE) -s run

# Compilação dos objetos
objs: $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXT) $(INCDIR)/%.$(EXTINC)
	@ $(CC) $(FLAGS) -c $< -I $(INCDIR) -o $@

run:
	$(if $(ECHO),@echo Makefile: Running Program)
	$(if $(ECHO),@echo =-=-=-=-=-=-=-=-=-=-=-=-=)
	@ $(BINDIR)/$(APP)
	$(if $(ECHO),@echo =-=-=-=-=-=-=-=-=-=-=-=-=)
	$(if $(ECHO),@echo Makefile: Program Ended)
	@ $(MAKE) -s clean

# Limpeza dos arquivos
.PHONY: clean

clean:
	$(if $(ECHO),@echo Makefile: Cleaning)
ifeq ($(OS),Windows_NT)
	@ if exist "$(BINDIR)" rd /s /q $(BINDIR)
	@ if exist "$(OBJDIR)" rd /s /q $(OBJDIR)
else
	@ if [ -d "$(BINDIR)" ]; then rm -rf $(BINDIR); fi
	@ if [ -d "$(OBJDIR)" ]; then rm -rf $(OBJDIR); fi
endif
	$(if $(ECHO),@echo Makefile: Cleaned Successfully)
```