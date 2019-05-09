.PHONY: all clean install uninstall
CC = gcc
CFLAGS = -Wall -Werror
GEOMETRY := ./bin/geometry
INSTALL_PATH := /usr/local/bin
BUILD_SRC_DIR := ./build/src

all: $(GEOMETRY)

$(GEOMETRY): $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/input_output.o $(BUILD_SRC_DIR)/description_shape.o
	gcc $(CCFLAGS) $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/input_output.o $(BUILD_SRC_DIR)/description_shape.o -o $(GEOMETRY) -lm

$(BUILD_SRC_DIR)/main.o: src/main.c
	gcc $(CCFLAGS) -c src/main.c -o $(BUILD_SRC_DIR)/main.o

$(BUILD_SRC_DIR)/input_output.o: src/input_output.c
	gcc $(CCFLAGS) -c src/input_output.c -o $(BUILD_SRC_DIR)/input_output.o -lm

$(BUILD_SRC_DIR)/description_shape.o: src/description_shape.c
	gcc $(CCFLAGS) -c src/description_shape.c -o $(BUILD_SRC_DIR)/description_shape.o -lm

clean:
	rm -rf $(BUILD_SRC_DIR)/*.o bin/geometry

install: 
	install bin/geometry $(INSTALL_PATH)

uninstall:
	rm -rf $(INSTALL_PATH)/geometry