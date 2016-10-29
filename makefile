all: app.out

app.out: main.o player.o smath.o ray.o bullet.o
	g++ -o app.out main.o player.o smath.o ray.o bullet.o -lsfml-graphics -lsfml-window -lsfml-system	

main.o: main.cpp
	g++ -c main.cpp

player.o: player.cpp
	g++ -c player.cpp

smath.o: smath.cpp
	g++ -c smath.cpp

ray.o: ray.cpp
	g++ -c ray.cpp

bullet.o: bullet.cpp
	g++ -c bullet.cpp

clean:
	rm app.out main.o player.o smath.o ray.o bullet.o .*.swp 
