CC := g++
CFLAGS := -Wall -Wextra -fsanitize=address -Wpedantic -g
SRC := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp, build/%.o, $(SRC))
all: build/exprcalc
build/exprcalc: $(OBJS)
	@echo "Building binary..."
	@$(CC) $(CFLAGS) $^ -o $@
build/%.o: src/%.cpp
	@echo "Compiling..." $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r build/*.o build/exprcalc
