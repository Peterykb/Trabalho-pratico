# Nome do executável
TARGET = bin/main.exe

# Compilador
CC = gcc

# Diretórios
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
DADOS_DIR = dados

# Arquivos fonte
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/adicionar.c $(SRC_DIR)/deletar.c $(SRC_DIR)/editar.c $(SRC_DIR)/visualizar.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Flags do compilador
CFLAGS = -Wall -Wextra -I$(INC_DIR)

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Regra para compilar os arquivos .c em .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e binário
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

# Limpa e recompila tudo
rebuild: clean all
