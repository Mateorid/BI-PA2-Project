#	.PHONY == defines that it's a command and not creating any files
#	$@ == the name of the command and the file that I create. (The stuff before : )
#	$< == first dependence
#	$^ == all dependencies
#	@ before command silences it in the terminal

CXX			= g++
CXXFLAGS	= -std=c++14 -Wall -pedantic -g -O3
LDLIBS		= -lSDL2 -lSDL2_image #-lSDL2_ttf
DEST_DIR	= obj
TARGET		= arkanoid

.PHONY: all
all: $(TARGET) #doc

.PHONY: run
run: $(TARGET)
	@./$(TARGET)

.PHONY: valgrind
valgrind: $(TARGET)
	@valgrind --gen-suppressions=all --suppressions=./ValgrindSuppression.sup --leak-check=full --show-leak-kinds=all  ./$(TARGET)

doc:
#	doxygen

$(TARGET): $(DEST_DIR)/main.o $(DEST_DIR)/Game.o $(DEST_DIR)/TextureLoader.o $(DEST_DIR)/GameObject.o  $(DEST_DIR)/Platform.o $(DEST_DIR)/Ball.o $(DEST_DIR)/Block.o
	$(CXX) $(CXXFLAGS) $^ -g -o $@ $(LDLIBS)
	@echo "Starting..."

$(DEST_DIR)/%.o: src/%.cpp | $(DEST_DIR)
	@echo "Compiling..."
	$(CXX) $(CXXFLAGS) -c -g $< -o $@ $(LDLIBS)

$(DEST_DIR):
	@mkdir -p $(DEST_DIR)

.PHONY: clean
clean:
	@rm -rf $(TARGET) $(DEST_DIR)/ 2>/dev/null
	@echo "Files deleted"

#Dependencies
$(DEST_DIR)/main.o: src/main.cpp src/Game.hpp src/Settings.hpp src/GameObject.hpp src/TextureLoader.hpp src/Platform.hpp src/Ball.hpp src/Lives.hpp src/Block.hpp
$(DEST_DIR)/Game.o: src/Game.cpp src/Game.hpp src/Settings.hpp src/GameObject.hpp src/TextureLoader.hpp src/Platform.hpp src/Ball.hpp src/Lives.hpp src/Block.hpp
$(DEST_DIR)/TextureLoader.o: src/TextureLoader.cpp src/TextureLoader.hpp src/Game.hpp src/Settings.hpp src/GameObject.hpp src/Platform.hpp
$(DEST_DIR)/GameObject.o: src/GameObject.cpp src/GameObject.hpp src/Game.hpp src/Settings.hpp src/Platform.hpp src/TextureLoader.hpp src/Lives.hpp src/Block.hpp
$(DEST_DIR)/Platform.o: src/Platform.cpp src/Platform.hpp src/GameObject.hpp src/Game.hpp src/Settings.hpp src/TextureLoader.hpp src/Lives.hpp
$(DEST_DIR)/Ball.o: src/Ball.cpp src/Ball.hpp src/GameObject.hpp src/Settings.hpp src/TextureLoader.hpp src/Lives.hpp
$(DEST_DIR)/Block.o:src/Block.cpp src/Block.hpp src/GameObject.hpp src/Settings.hpp src/TextureLoader.hpp

