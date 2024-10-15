CC=g++
CFLAGS= -std=c++17 -I "/System/Volumes/Data/opt/homebrew/Cellar/raylib/5.0/include/"
LDFLAGS= -L "/System/Volumes/Data/opt/homebrew/Cellar/raylib/5.0/lib" -lraylib
TARGET=main
# Include all necessary source files
SOURCE=src/TestFile.cpp src/pet-essentials/Coin.cpp

CLASSES = Coin.hpp


all: $(TARGET)

# Header Class files

CLASSES = 


$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
	@$(MAKE) clean