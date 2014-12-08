
export CC=g++
export CFLAGS=-W -Wall -ansi -pedantic -std=c++0x -O2
export LDFLAGS=
export EXEC=Asphodale
export SRC_DIR=SRC

all: $(EXEC)

$(EXEC):
	@(cd $(SRC_DIR) && $(MAKE))


clean:
	rm -rf $(SRC_DIR)/*.o
	rm -rf $(EXEC)
