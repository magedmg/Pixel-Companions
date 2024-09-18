CC=g++
CFLAGS= -std=c++17 -I "/System/Volumes/Data/opt/homebrew/Cellar/raylib/5.0/include/"
LDFLAGS= -L "/System/Volumes/Data/opt/homebrew/Cellar/raylib/5.0/lib" -lraylib
TARGET=main
SOURCE=src/main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
	@$(MAKE) clean