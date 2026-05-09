CC := g++
CFLAGS := -Wall -Wextra -fsanitize=address -Wpedantic -g

SRC := $(wildcard src/*.cpp)
SRC_T := $(wildcard src/tools/*.cpp)

OBJS := $(patsubst src/%.cpp,build/%.o,$(SRC))
OBJS_T := $(patsubst src/tools/%.cpp,build/tools/%.o,$(SRC_T))

TARGET := build/exprcalc

all: $(TARGET)

$(TARGET): $(OBJS) $(OBJS_T)
	@echo "Building binary..."
	@$(CC) $(CFLAGS) $^ -o $@

build/%.o: src/%.cpp | build
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

build/tools/%.o: src/tools/%.cpp | build/tools
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

build/tools:
	mkdir -p build/tools

clean:
	rm -rf build