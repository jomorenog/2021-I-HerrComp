all: datos.pdf

updown.x : up_down.cpp
	g++ up_down.cpp -o updown.x

datos.txt : updown.x
	./updown.x 1000 > datos.txt

datos.pdf: updown.gp datos.txt
	gnuplot updown.gp

clean:
	rm -f datos.txt updown.x
