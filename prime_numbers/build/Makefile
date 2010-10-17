#################################################
# Makefile para compilacap de codigo para o PS3 #
# Autor: Eduardo Marques                        #
# Data: 29/09/2010                              #
#################################################

# Para criar uma biblioteca estática
# ar  rcs libmean.a      calc_mean.o

vpath %.h ../include
vpath %.h ../include/tests
vpath %.c ../src
vpath %.c ../src/tests

# Compiladores
#CXX=spu-g++
#CC=ppu-gcc
CXX=g++
CC=gcc
SPU_CC=spu-gcc
EMBED_CC=ppu-embedspu

# Nomes de programas
MAIN_NAME = prime_number_serial
SPU_NAME=hello_spu
BIN = $(MAIN_NAME)
TEST_NAME = run_tests

# Nomes dos arquivos objetos
OBJ = $(MAIN_NAME).o
TESTS_OBJ = CuTest.o AllTests.o prime_number_serial_test.o
SPU_OBJ = $(SPU_NAME).spuo
SPU_PPU_OBJ = $(SPU_NAME).o

# Flags de compilacao
CORE_LIB = 
SPU_SRC_DIR = ../src

LIB_DIR = -L ../lib
LIBS = -lspe2 -lpthread
INCLUDE_DIRS = -I ../include -I ../include/tests

CXXFLAGS = $(INCLUDE_DIRS) -Wall
CFLAGS = $(INCLUDE_DIRS) -Wall
LDFLAGS = --cref -s -o $(MAIN_NAME) -Wl $(LIB_DIR) $(LIBS)
CU_TEST_FLAGS =  --cref -s -o $(TEST_NAME) -Wl $(LIB_DIR)

all: $(BIN)
	@echo "*** Fim do Processo de Compilacao***"

spu_bin: 
	$(SPU_CC) $(CFLAGS) -o $(SPU_OBJ) $(SPU_SRC_DIR)/$(SPU_NAME).c

embed_spu: spu_bin
	$(EMBED_CC) $(SPU_NAME) $(SPU_OBJ) $(SPU_PPU_OBJ)
	
#$(BIN): embed_spu $(OBJ) 
#	$(CC) $(OBJ) $(SPU_PPU_OBJ) $(LDFLAGS) 
$(BIN): $(OBJ) 
	$(CC) $(OBJ) $(SPU_PPU_OBJ) $(LDFLAGS) 

tests: $(OBJ) $(TESTS_OBJ)
	$(CC) $(OBJ) $(TESTS_OBJ) $(CU_TEST_FLAGS)

.PHONY: clean
clean:
	rm -vf $(OBJ) $(TESTS_OBJ) $(SPU_OBJ) $(SPU_PPU_OBJ) $(BIN) $(MAIN_NAME) $(TEST_NAME)
