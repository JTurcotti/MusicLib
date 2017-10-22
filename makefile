Music: song_list.o song_node.o song_lib.o main.o
	gcc -o Music *.o

main.o: main.c
	gcc -g -c main.c

song_node.o song_list.o song_lib.o: song_node.c song_list.c song_lib.c
	gcc -g -c song_node.c song_list.c song_lib.c

run: Music
	./Music

clean:
	find . -name '*.o' -delete
