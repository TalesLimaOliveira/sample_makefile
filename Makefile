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
	@ if not exist "$(LIBDIR)" mkdir $(LIBDIR)
else
	@ mkdir -p $(BINDIR) $(OBJDIR) $(LIBDIR)
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
	@ if exist "$(LIBDIR)" del /q $(LIBDIR)
	@ if exist "$(BINDIR)" rmdir $(BINDIR)
	@ if exist "$(OBJDIR)" rmdir $(OBJDIR)
	@ if exist "$(LIBDIR)" rmdir $(LIBDIR)
else
	@ rm -rf $(OBJDIR)/* $(BINDIR)/* $(LIBDIR)/*
	@ rmdir $(OBJDIR) $(BINDIR) $(LIBDIR)
endif
	@ echo Makefile: Cleaned Successfully
