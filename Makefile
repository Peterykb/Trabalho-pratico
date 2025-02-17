# Compilador
CC = gcc

# Diretórios
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Arquivos fonte
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/adicionar.c \
       $(SRC_DIR)/excluir.c \
       $(SRC_DIR)/editar.c \
       $(SRC_DIR)/visualizar.c \
       $(SRC_DIR)/executarEntrega.c \
       $(SRC_DIR)/gerarRelatorio.c

# Arquivos objeto gerados
OBJS = $(SRCS:.c=.o)

# Executável final
OUT = $(BIN_DIR)/main.exe

# Flags de compilação
CFLAGS = -I$(INCLUDE_DIR)

# Regra principal: compilar o programa
$(OUT): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT)

# Compilar cada arquivo .c individualmente
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretório bin se não existir
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpar arquivos compilados
clean:
	rm -f $(SRC_DIR)/*.o $(OUT)
