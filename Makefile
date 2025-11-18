# Makefile for building all LeetCode solution files separately

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRC_DIR = src
BUILD_DIR = build

# Find all .cpp files in src directory
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Get base names (without directory and extension)
BASENAMES := $(basename $(notdir $(SOURCES)))

# For files with main(), create executables in build/bin
# For files without main(), create object files in build/obj
EXECUTABLES := $(addprefix $(BUILD_DIR)/bin/, $(BASENAMES))
OBJECTS := $(addprefix $(BUILD_DIR)/obj/, $(addsuffix .o, $(BASENAMES)))

.PHONY: all clean executables objects help

# Default target: try to build all files
all: $(BUILD_DIR) executables objects
	@echo "Build complete!"
	@echo "Executables: $$(find $(BUILD_DIR)/bin -type f 2>/dev/null | wc -l)"
	@echo "Object files: $$(find $(BUILD_DIR)/obj -type f -name '*.o' 2>/dev/null | wc -l)"

# Create build directories
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)/bin
	@mkdir -p $(BUILD_DIR)/obj

# Target to build only executables (files with main)
executables: $(BUILD_DIR)
	@echo "Building executables..."
	@for src in $(SOURCES); do \
		base=$$(basename $$src .cpp); \
		if grep -q "int main" $$src; then \
			echo "Building executable: $$base"; \
			$(CXX) $(CXXFLAGS) $$src -o $(BUILD_DIR)/bin/$$base || true; \
		fi \
	done

# Target to build only object files (files without main)
objects: $(BUILD_DIR)
	@echo "Building object files..."
	@for src in $(SOURCES); do \
		base=$$(basename $$src .cpp); \
		if ! grep -q "int main" $$src; then \
			echo "Building object: $$base.o"; \
			$(CXX) $(CXXFLAGS) -c $$src -o $(BUILD_DIR)/obj/$$base.o || true; \
		fi \
	done

# Build a specific file by name (e.g., make build-1 or make build-11)
build-%: $(BUILD_DIR)
	@if [ -f "$(SRC_DIR)/$*.cpp" ]; then \
		if grep -q "int main" $(SRC_DIR)/$*.cpp; then \
			echo "Building executable: $*"; \
			$(CXX) $(CXXFLAGS) $(SRC_DIR)/$*.cpp -o $(BUILD_DIR)/bin/$*; \
		else \
			echo "Building object file: $*.o"; \
			$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/$*.cpp -o $(BUILD_DIR)/obj/$*.o; \
		fi \
	else \
		echo "Error: $(SRC_DIR)/$*.cpp not found"; \
		exit 1; \
	fi

# Clean build artifacts
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete!"

# Help target
help:
	@echo "LeetCode Solutions Build System"
	@echo "================================"
	@echo ""
	@echo "Available targets:"
	@echo "  make all          - Build all files (executables and object files)"
	@echo "  make executables  - Build only files with main() function"
	@echo "  make objects      - Build only files without main() function"
	@echo "  make build-N      - Build specific file N.cpp (e.g., make build-1)"
	@echo "  make clean        - Remove all build artifacts"
	@echo "  make help         - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make build-1      - Build src/1.cpp into build/bin/1"
	@echo "  make build-11     - Build src/11.cpp into build/obj/11.o"
