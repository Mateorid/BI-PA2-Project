#	.PHONY == defines that it's a command and not creating any files
#	$@ == the name of the command and the file that I create. (The stuff before : )
#	$< == first dependence
#	$^ == all dependencies
#	@ before command silences it in the terminal

CXX			= g++
CXXFLAGS	= -std=c++14 -Wall -pedantic -g -O3
LDLIBS		= -lSDL2 -lSDL2_image -lSDL2_ttf
DEST_DIR	= obj
TARGET		= arkanoid

.PHONY: all
all: $(TARGET) doc

.PHONY: run
run: $(TARGET)
	@./$(TARGET)

.PHONY: valgrind
valgrind: $(TARGET)
	@valgrind --gen-suppressions=all --suppressions=./ValgrindSuppression.sup --leak-check=full --show-leak-kinds=all  ./$(TARGET) -g

doc:
	@mkdir -p doc
#	doxygen

$(TARGET): $(DEST_DIR)/Ball.o\
           $(DEST_DIR)/Block.o\
           $(DEST_DIR)/Bonus.o\
           $(DEST_DIR)/ExitState.o\
           $(DEST_DIR)/GameObject.o\
           $(DEST_DIR)/GameState.o\
           $(DEST_DIR)/LoadState.o\
           $(DEST_DIR)/main.o\
           $(DEST_DIR)/MapLoader.o\
           $(DEST_DIR)/MenuState.o\
           $(DEST_DIR)/Platform.o\
           $(DEST_DIR)/ScoreManager.o\
           $(DEST_DIR)/StartupState.o\
           $(DEST_DIR)/State.o\
           $(DEST_DIR)/StateManager.o\
           $(DEST_DIR)/TextPrinter.o\
           $(DEST_DIR)/VictoryState.o

	$(CXX) $(CXXFLAGS) $^ -g -o $@ $(LDLIBS)
	@echo "Starting..."

$(DEST_DIR)/%.o: src/%.cpp | $(DEST_DIR)
	@echo "Compiling..."
	$(CXX) $(CXXFLAGS) -c -g $< -o $@ $(LDLIBS)

$(DEST_DIR):
	@mkdir -p $(DEST_DIR)

.PHONY: clean
clean:
	@rm -rf $(TARGET)
	@rm -rf $(DEST_DIR)/ 2>/dev/null
	@rm -rf doc 2>/dev/null
	@echo "Files deleted"

#Dependencies
$(DEST_DIR)/Ball.o: src/Ball.cpp src/Ball.hpp src/GameObject.hpp src/ScoreManager.hpp \
 src/State.hpp src/StateManager.hpp src/TextPrinter.hpp src/Platform.hpp \
 src/Bonus.hpp
$(DEST_DIR)/Block.o: src/Block.cpp src/Block.hpp src/GameObject.hpp
$(DEST_DIR)/Bonus.o: src/Bonus.cpp src/Bonus.hpp src/GameObject.hpp \
 src/ScoreManager.hpp src/State.hpp src/StateManager.hpp \
 src/TextPrinter.hpp src/Platform.hpp src/Ball.hpp
$(DEST_DIR)/ExitState.o: src/ExitState.cpp src/ExitState.hpp src/State.hpp \
 src/StateManager.hpp src/TextPrinter.hpp src/GameObject.hpp \
 src/Platform.hpp src/Ball.hpp src/ScoreManager.hpp src/Bonus.hpp
$(DEST_DIR)/GameObject.o: src/GameObject.cpp src/GameObject.hpp
$(DEST_DIR)/GameState.o: src/GameState.cpp src/GameState.hpp src/State.hpp \
 src/StateManager.hpp src/TextPrinter.hpp src/GameObject.hpp \
 src/Platform.hpp src/Ball.hpp src/ScoreManager.hpp src/Bonus.hpp
$(DEST_DIR)/LoadState.o: src/LoadState.cpp src/LoadState.hpp src/State.hpp \
 src/StateManager.hpp src/TextPrinter.hpp src/GameObject.hpp \
 src/Platform.hpp src/Ball.hpp src/ScoreManager.hpp src/Bonus.hpp \
 src/MapLoader.hpp src/Block.hpp
$(DEST_DIR)/main.o: src/main.cpp src/StateManager.hpp src/State.hpp \
 src/TextPrinter.hpp src/GameObject.hpp src/Platform.hpp src/Ball.hpp \
 src/ScoreManager.hpp src/Bonus.hpp src/StartupState.hpp \
 src/MenuState.hpp src/LoadState.hpp src/MapLoader.hpp src/Block.hpp \
 src/GameState.hpp src/ResultState.hpp src/ExitState.hpp
$(DEST_DIR)/MapLoader.o: src/MapLoader.cpp src/MapLoader.hpp src/Block.hpp \
 src/GameObject.hpp src/State.hpp src/StateManager.hpp \
 src/TextPrinter.hpp src/Platform.hpp src/Ball.hpp src/ScoreManager.hpp \
 src/Bonus.hpp
$(DEST_DIR)/MenuState.o: src/MenuState.cpp src/MenuState.hpp src/State.hpp \
 src/StateManager.hpp src/TextPrinter.hpp src/GameObject.hpp \
 src/Platform.hpp src/Ball.hpp src/ScoreManager.hpp src/Bonus.hpp
$(DEST_DIR)/Platform.o: src/Platform.cpp src/Platform.hpp src/GameObject.hpp \
 src/State.hpp src/StateManager.hpp src/TextPrinter.hpp src/Ball.hpp \
 src/ScoreManager.hpp src/Bonus.hpp
$(DEST_DIR)/ScoreManager.o: src/ScoreManager.cpp src/ScoreManager.hpp \
 src/GameObject.hpp src/State.hpp src/StateManager.hpp \
 src/TextPrinter.hpp src/Platform.hpp src/Ball.hpp src/Bonus.hpp
$(DEST_DIR)/StartupState.o: src/StartupState.cpp src/StartupState.hpp src/State.hpp \
 src/StateManager.hpp src/TextPrinter.hpp src/GameObject.hpp \
 src/Platform.hpp src/Ball.hpp src/ScoreManager.hpp src/Bonus.hpp
$(DEST_DIR)/State.o: src/State.cpp src/State.hpp src/StateManager.hpp \
 src/TextPrinter.hpp src/GameObject.hpp src/Platform.hpp src/Ball.hpp \
 src/ScoreManager.hpp src/Bonus.hpp
$(DEST_DIR)/StateManager.o: src/StateManager.cpp src/StateManager.hpp src/State.hpp \
 src/TextPrinter.hpp src/GameObject.hpp src/Platform.hpp src/Ball.hpp \
 src/ScoreManager.hpp src/Bonus.hpp
$(DEST_DIR)/TextPrinter.o: src/TextPrinter.cpp src/TextPrinter.hpp
$(DEST_DIR)/VictoryState.o: src/ResultState.cpp src/ResultState.hpp src/State.hpp \
 src/StateManager.hpp src/TextPrinter.hpp src/GameObject.hpp \
 src/Platform.hpp src/Ball.hpp src/ScoreManager.hpp src/Bonus.hpp