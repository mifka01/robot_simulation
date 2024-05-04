# Doxygen
DOCS_DIR := doc
DOXYFILE := Doxyfile

BUILD_DIR := build
SRC_DIR := src
INCLUDE_DIR := include
EXAMPLES_DIR := examples

# Output executable
TARGET := robots

# Output archive
ARCHIVE := xmifka00.zip

.PHONY: build
build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && make -j 16
	# for vim
	cp $(BUILD_DIR)/compile_commands.json .

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(DOCS_DIR)

# Phony target to run the executable
.PHONY: run
run: build $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)

# Target to generate documentation
.PHONY: docs
docs: $(DOXYFILE)
	doxygen $(DOXYFILE)

# Pack method to create a zip archive
.PHONY: pack
pack:
	cp README.md README.txt
	find $(SRC_DIR) $(INCLUDE_DIR) $(EXAMPLES_DIR) -type f -not -path '*/\.*' -not -name '*.DS_Store' | zip -@ $(ARCHIVE) $(SRC_DIR) $(INCLUDE_DIR) $(EXAMPLES_DIR) Makefile README.txt CMakeLists.txt Doxyfile
	rm README.txt

# Default target
.DEFAULT_GOAL := build
