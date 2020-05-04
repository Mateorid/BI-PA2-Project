CXX			= g++
CXXFLAGS	= -std=c++17 -Wall -pedantic -g -O3
LDLIBS		= -lSDL2 -lSDL2_image
DEST_DIR	= obj
TARGET		= tank

all: tank doc

#.PHONY: run
run: $(TARGET)
	./$(TARGET)

doc:
#	doxygen

$(TARGET): $(DEST_DIR)/main.o $(DEST_DIR)/Game.o $(DEST_DIR)/TextureLoader.o $(DEST_DIR)/GameObject.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

$(DEST_DIR)/%.o: src/%.cpp | $(DEST_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDLIBS)

$(DEST_DIR):
	mkdir -p $(DEST_DIR)

#.PHONY: clean
clean:
	rm -rf $(TARGET) $(DEST_DIR)/ 2>/dev/null

#Dependencies
$(DEST_DIR)/main.o: src/main.cpp src/Game.hpp src/Settings.hpp
$(DEST_DIR)/Game.o: src/Game.cpp src/Game.hpp src/TextureLoader.hpp src/GameObject.hpp
$(DEST_DIR)/TextureLoader.o: src/TextureLoader.cpp src/TextureLoader.hpp src/Game.hpp
$(DEST_DIR)/GameObject.o: src/GameObject.cpp src/GameObject.hpp src/Game.hpp src/TextureLoader.hpp