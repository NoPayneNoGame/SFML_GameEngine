all: app.out

app.out: main.o game.o scenemanager.o scene.o player.o testscene.o smath.o ray.o bullet.o
	g++ -o app.out main.o game.o scenemanager.o scene.o player.o testscene.o smath.o ray.o bullet.o -lsfml-graphics -lsfml-window -lsfml-system	

main.o: src/main.cpp
	g++ -I include/ -c src/main.cpp

game.o: src/game.cpp
	g++ -I include/ -c src/game.cpp

scenemanager.o: src/scenemanager.cpp
	g++ -I include/ -c src/scenemanager.cpp

scene.o: src/scene.cpp
	g++ -I include/ -c src/scene.cpp

player.o: src/player.cpp
	g++ -I include/ -c src/player.cpp

testscene.o: src/testscene.cpp
	g++ -I include/ -c src/testscene.cpp

smath.o: src/smath.cpp
	g++ -I include/ -c src/smath.cpp

ray.o: src/ray.cpp
	g++ -I include/ -c src/ray.cpp

bullet.o: src/bullet.cpp
	g++ -I include/ -c src/bullet.cpp

clean:
	rm app.out *.o .*.swp 

