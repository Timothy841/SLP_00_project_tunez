all: main.o song_node.o song_library.o
	gcc -o main main.o song_node.o song_library.o

main.o: main.c song_node.h song_library.h
	gcc -c main.c

song_node.o: song_node.c
	gcc -c song_node.c

song_library.o: song_library.c
	gcc -c song_library.c

clean:
	rm *.o

run:
	./main
