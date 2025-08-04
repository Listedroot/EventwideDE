CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0) -lasound

SRC_DESKTOP = $(wildcard desktop/*.c)
SRC_WM = $(wildcard window_manager/*.c)
SRC_TASKBAR = $(wildcard taskbar/*.c)
SRC_STARTMENU = $(wildcard start_menu/*.c)
SRC_COMMON = $(wildcard common/*.c)

OBJ_DESKTOP = $(SRC_DESKTOP:.c=.o)
OBJ_WM = $(SRC_WM:.c=.o)
OBJ_TASKBAR = $(SRC_TASKBAR:.c=.o)
OBJ_STARTMENU = $(SRC_STARTMENU:.c=.o)
OBJ_COMMON = $(SRC_COMMON:.c=.o)

BIN_DESKTOP = eventwidede-desktop
BIN_WM = eventwidede-wm
BIN_TASKBAR = eventwidede-taskbar
BIN_STARTMENU = eventwidede-startmenu

all: $(BIN_DESKTOP) $(BIN_WM) $(BIN_TASKBAR) $(BIN_STARTMENU)

$(BIN_DESKTOP): $(OBJ_DESKTOP) $(OBJ_COMMON)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BIN_WM): $(OBJ_WM) $(OBJ_COMMON)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BIN_TASKBAR): $(OBJ_TASKBAR) $(OBJ_COMMON)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BIN_STARTMENU): $(OBJ_STARTMENU) $(OBJ_COMMON)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f desktop/*.o window_manager/*.o taskbar/*.o start_menu/*.o common/*.o
	rm -f $(BIN_DESKTOP) $(BIN_WM) $(BIN_TASKBAR) $(BIN_STARTMENU)

.PHONY: all clean
