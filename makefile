# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -I.

# Libraries to link
LDFLAGS = -lcurl

# Target executable
TARGET = generate_ad

# Source files
SRCS = main.c tts.c video.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compiling source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(TARGET) $(OBJS)

# Rebuild the project from scratch
rebuild: clean all

# Phony targets to avoid conflicts with files named 'clean' or 'rebuild'
.PHONY: all clean rebuild
