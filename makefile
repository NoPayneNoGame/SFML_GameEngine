all: app.out

app.out: main.o player.o smath.o ray.o bullet.o
	g++ -o app.out main.o player.o smath.o ray.o bullet.o -lsfml-graphics -lsfml-window -lsfml-system	

main.o: src/main.cpp
	g++ -I include/ -c src/main.cpp

player.o: src/player.cpp
	g++ -I include/ -c src/player.cpp

smath.o: src/smath.cpp
	g++ -I include/ -c src/smath.cpp

ray.o: src/ray.cpp
	g++ -I include/ -c src/ray.cpp

bullet.o: src/bullet.cpp
	g++ -I include/ -c src/bullet.cpp

clean:
	rm app.out main.o player.o smath.o ray.o bullet.o .*.swp 
