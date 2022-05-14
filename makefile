NULL =
TAB  = $(NULL)    $(NULL)

# aliased options
all: d b
o: options
d: debug
b: build
cl: clean
cf: cleanf

# options for make
options:
	$(info USAGE:)
	$(info $(TAB)make  o | options   -- display options)
	$(info $(TAB)make  d | debug     -- debug build)
	$(info $(TAB)make  b | build     -- optimised prime_cnt build)
	$(info $(TAB)make cl | clean     -- delete binaries)
	$(info $(TAB)make cf | cleanf    -- force delete binaries)
	@exit

# required stuff
CC        = gcc
DBG       = gdb -q
DBG_FLAGS = -Wall -D DEBUG="(1)" -g3 -ggdb
REL_FLAGS = -Wall -Ofast

SRC_DIR   = ./src
BIN_DIR   = .

SRC_PATH  = $(SRC_DIR)/*.c
DBG_PATH  = $(BIN_DIR)/prime_cnt_dbg
REL_PATH  = $(BIN_DIR)/prime_cnt

# clear screen
clscr:
	clear

# builds debug prime_cnt
debug:
	$(CC) $(DBG_FLAGS) $(SRC_PATH) -o $(DBG_PATH)

# compile source to bin path
build:
	$(CC) $(REL_FLAGS) $(SRC_PATH) -o $(REL_PATH)

# clear binaries
clean:
	rm prime_cnt_dbg prime_cnt

# force clear binaries
cleanf:
	rm -f prime_cnt_dbg prime_cnt
