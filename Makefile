# Compilador
CC = gcc

# Diretórios
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Arquivos-fonte
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/adicionar.c $(SRC_DIR)/deletar.c $(SRC_DIR)/editar.c $(SRC_DIR)/visualizar.c

# Objetos (arquivos compilados .o)
OBJS = $(SRCS:.c=.o)

# Arquivo executável de saída
OUT = $(BIN_DIR)/main.exe

# Flags de compilação (inclui a pasta include)
CFLAGS = -I$(INCLUDE_DIR)

# Regra para compilar o programa
$(OUT): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

# Regra para compilar arquivos .c em .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Garante que a pasta bin existe antes de compilar
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OUT) $(SRC_DIR)/*.o
