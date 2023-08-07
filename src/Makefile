TRASH=*.out ../build*
BUILD_DIR=../build

build:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_CXX_COMPILER=g++

d: build
	make -C $(BUILD_DIR) maze_debug
	./$(BUILD_DIR)/maze_debug

leaks: d
	leaks --atExit -- ./$(BUILD_DIR)/maze_debug

clean:
	rm -rf $(TRASH)