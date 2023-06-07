CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Directories
SRC_DIR = .
DATE_DIR = Date
INVESTIGATION_DIR = Investigation
MENU_DIR = Menu
STORAGE_DIR = Storage

# Source files
MAIN_SRC = $(SRC_DIR)/main.cpp
# MAIN_SRC = $(SRC_DIR)/test.cpp
DATE_SRC = $(DATE_DIR)/Date.cpp
INVESTIGATION_SRC = $(INVESTIGATION_DIR)/Investigation.cpp
BASIS_SRC = $(INVESTIGATION_DIR)/Basis/Basis.cpp
MENU_SRC = $(MENU_DIR)/Menu.cpp
STORAGE_SRC = $(STORAGE_DIR)/Storage.cpp

# Object files
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
DATE_OBJ = $(DATE_SRC:.cpp=.o)
INVESTIGATION_OBJ = $(INVESTIGATION_SRC:.cpp=.o)
BASIS_OBJ = $(BASIS_SRC:.cpp=.o)
MENU_OBJ = $(MENU_SRC:.cpp=.o)
STORAGE_OBJ = $(STORAGE_SRC:.cpp=.o)

# Executable
TARGET = program

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(DATE_OBJ) $(INVESTIGATION_OBJ) $(BASIS_OBJ) $(MENU_OBJ) $(STORAGE_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DATE_OBJ): $(DATE_SRC) $(DATE_DIR)/Date.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(INVESTIGATION_OBJ): $(INVESTIGATION_SRC) $(INVESTIGATION_DIR)/Investigation.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BASIS_OBJ): $(BASIS_SRC) $(INVESTIGATION_DIR)/Basis/Basis.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(MENU_OBJ): $(MENU_SRC) $(MENU_DIR)/Menu.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(STORAGE_OBJ): $(STORAGE_SRC) $(STORAGE_DIR)/Storage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(DATE_OBJ) $(INVESTIGATION_OBJ) $(BASIS_OBJ) $(MENU_OBJ) $(STORAGE_OBJ)

