SRC_DIR := src
BIN_DIR := build
INCLUDE_DIR := include

EXE := $(BIN_DIR)/gameOfLife
SRC := $(SRC_DIR)/main.cpp $(SRC_DIR)/file.cpp $(SRC_DIR)/grid.cpp $(SRC_DIR)/simulation.cpp

CPPFLAGS := -I$(SRC_DIR) -I$(INCLUDE_DIR) -Iraylib-quickstart
CFLAGS   := -g -std=c++17 -Wall
LDFLAGS  := -Lraylib-quickstart
LDLIBS   := -lraylib -lm -lpthread -ldl
CC := g++

.PHONY: all clean

all: $(EXE)

$(EXE): $(SRC) | $(BIN_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BIN_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR)
