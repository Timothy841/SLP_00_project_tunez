all: main.o song_node.o
	gcc -o main main.o song_node.o

main.o: main.c song_node.h
	gcc -c main.c

song_node.o: song_node.c
	gcc -c song_node.c

clean:
	rm *.o

run:
	./main
