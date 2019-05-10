.PHONY: all clean install uninstall
CC = gcc
CFLAGS = -Wall -Werror
GEOMETRY := ./bin/geometry
TEST := ./bin/test
INSTALL_PATH := /usr/local/bin
BUILD_SRC_DIR := ./build/src
BUILD_TEST_DIR := ./build/test

all: $(GEOMETRY)

$(GEOMETRY): $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/input_output.o $(BUILD_SRC_DIR)/description_shape.o
	gcc $(CCFLAGS) $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/input_output.o $(BUILD_SRC_DIR)/description_shape.o -o $(GEOMETRY) -lm

$(BUILD_SRC_DIR)/main.o: src/main.c
	gcc $(CCFLAGS) -c src/main.c -o $(BUILD_SRC_DIR)/main.o

$(BUILD_SRC_DIR)/input_output.o: src/input_output.c
	gcc $(CCFLAGS) -c src/input_output.c -o $(BUILD_SRC_DIR)/input_output.o -lm

$(BUILD_SRC_DIR)/description_shape.o: src/description_shape.c
	gcc $(CCFLAGS) -c src/description_shape.c -o $(BUILD_SRC_DIR)/description_shape.o -lm

test: $(TEST)

$(TEST): $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/input_output.o $(BUILD_TEST_DIR)/description_shape.o
	gcc $(CCFLAGS) $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/input_output.o $(BUILD_TEST_DIR)/description_shape.o -o $(TEST) -lm

$(BUILD_TEST_DIR)/main.o: test/main.c
	gcc $(CCFLAGS) -c -I thirdparty -I src test/main.c -o $(BUILD_TEST_DIR)/main.o

$(BUILD_TEST_DIR)/input_output.o: src/input_output.c
	gcc $(CCFLAGS) -c -I thirdparty -I src src/input_output.c -o $(BUILD_TEST_DIR)/input_output.o -lm

$(BUILD_TEST_DIR)/description_shape.o: src/description_shape.c
	gcc $(CCFLAGS) -c -I thirdparty -I src src/description_shape.c -o $(BUILD_TEST_DIR)/description_shape.o -lm

clean:
	rm -rf $(BUILD_SRC_DIR)/*.o $(BUILD_TEST_DIR)/*.o bin/geometry bin/test

install: 
	install bin/geometry $(INSTALL_PATH)

uninstall:
	rm -rf $(INSTALL_PATH)/geometry

run_test: test
	$(TEST)