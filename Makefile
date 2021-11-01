# Simple make file for SDL2 C sketches

OUT=hellosdl
SRC=hellosdl.c

FLAGS=-Wall `sdl2-config --cflags --libs`

all:build

build: $(SRC)
	clang $(SRC) -o $(OUT) $(FLAGS)

run: build
	./$(OUT)

clean:
	rm -rf $(OUT)