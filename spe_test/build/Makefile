#################################################
# Makefile para compilacap de codigo para o PS3 #
# Autor: Eduardo Marques                        #
# Data: 29/09/2010                              #
#################################################

vpath %.h ../include
vpath %.c ../src
# vpath %.cpp ../src

CXX=spu-g++
CC=ppu-gcc
SPU_CC=spu-gcc
MAIN_NAME = pi_libspe_ppe
OBJ = $(MAIN_NAME).o
CORE_LIB = 
BIN = $(MAIN_NAME)

LIB_DIR = -L ../lib
LIBS = -lspe2 -lpthread
INCLUDE_DIRS = -I ../include

CXXFLAGS = $(INCLUDE_DIRS) -Wall
CFLAGS = $(INCLUDE_DIRS) -Wall
LDFLAGS = --cref -s -o $(MAIN_NAME) -Wl $(LIB_DIR) $(LIBS)

all: $(BIN)
	@echo "*** Fim do Processo de Compilacao***"

$(BIN): $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) 

.PHONY: clean
clean:
	rm -vf $(OBJ) $(BIN) $(MAIN_NAME)
