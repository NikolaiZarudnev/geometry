.PHONY: all clean install uninstall
CCFLAGS := -Wall -Wextra
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
INSTALL_PATH := /usr/local/bin

all: $(BIN_DIR)/geometry

$(BIN_DIR)/geometry: $(OBJ_DIR)/main.o $(OBJ_DIR)/input_output.o $(OBJ_DIR)/description_shape.o
	gcc $(CCFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/input_output.o $(OBJ_DIR)/description_shape.o -o $(BIN_DIR)/geometry -lm

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc $(CCFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/input_output.o: $(SRC_DIR)/input_output.c
	gcc $(CCFLAGS) -c $(SRC_DIR)/input_output.c -o $(OBJ_DIR)/input_output.o -lm

$(OBJ_DIR)/description_shape.o: $(SRC_DIR)/description_shape.c
	gcc $(CCFLAGS) -c $(SRC_DIR)/description_shape.c -o $(OBJ_DIR)/description_shape.o -lm

$(SRC_DIR):
	mkdir src
$(BIN_DIR):
	mkdir bin
$(OBJ_DIR):
	mkdir build

clean:
	rm -rf $(OBJ_DIR)/*.o

install:
	install bin/geometry $(INSTALL_PATH)

uninstall:
	rm -rf $(INSTALL_PATH)/geometry