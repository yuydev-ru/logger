.PHONY: clean

CXX=g++
CXXFLAGS=-Wall -Wpedantic -ggdb -std=c++11
ifneq ($(OS),Windows_NT)
	ifeq ($(shell uname), Darwin)
		override CFLAGS += -arch x86_64
	endif
endif
PREFIX ?= .

INCLUDE_DIR = $(PREFIX)/include
LIB_DIR = $(PREFIX)/lib
BUILD_DIR = $(PREFIX)/build
PACKAGE_DIR = $(PREFIX)/package

TARGET=$(BUILD_DIR)/logger.o

all: $(TARGET)
$(TARGET): logger.h logger.cpp Makefile
	$(CXX) $(CXXFLAGS) -I./$(INCLUDE_DIR) -c logger.cpp -o $(BUILD_DIR)/logger.o

clean:
ifeq ($(OS),Windows_NT)
	del /q "$(BUILD_DIR)\*"
else
	@rm -f "$(BUILD_DIR)/*"
endif