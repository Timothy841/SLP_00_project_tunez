#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "song_library.h"
#include "song_node.h"

struct song_node{
	struct song_node *next;
	char artist[30];
	char song[30];
};

struct song_node ** create_library(){
  struct song_node ** library = calloc(27*sizeof(struct song_node), sizeof(struct song_node));
  return library;
}

int find_letter(char *a){
  int alpha = (int)(tolower(a[0]))-97;
  if (alpha<0 || alpha > 25){
    alpha = 26;
  }
  return alpha;
}
struct song_node ** add_song(struct song_node **library, char *a, char *s){
  int alpha = find_letter(a);
  library[alpha] = insert_alpha(library[alpha], a, s);
  return library;
}

struct song_node * library_find_artist_song(struct song_node **library, char *a, char *s){
  int alpha = find_letter(a);
  return find_artist_song(library[alpha], a, s);
}

struct song_node * library_find_artist(struct song_node **library, char *a){
  int alpha = find_letter(a);
  return find_artist(library[alpha], a);
}

void library_print_list(struct song_node **library, char *a){
  int alpha = find_letter(a);
  print_list(library[alpha]);
}

void print_artist_songs(struct song_node **library, char *a){
  int alpha = find_letter(a);
  struct song_node *artist = find_artist(library[alpha], a);
  printf("Artist:%s\nSongs:", a);
  while (strcasecmp(artist->artist, a) == 0){
    if (artist->next == 0 || (artist->next) && strcasecmp(artist->next->artist, a)){//node is last
      printf("%s\n", artist->song);
      return;
    }
    else{
      printf("%s, ", artist->song);
      artist = artist->next;
    }
  }
}

void print_library(struct song_node **library){
  int a;
  for (a = 0; a<27; a++){
    print_list(library[a]);
  }
}

struct song_node ** delete_song(struct song_node **library, char *a, char *s){
  int alpha = find_letter(a);
  library[alpha] = remove_node(library[alpha], a, s);
  return library;
}

int size_library(struct song_node **library){
  int a = 0;
  int size = 0;
  while (a<27){
    size += sized(library[a]);
    a++;
  }

  return size;
}

int contains(int *a, int size, int i){
	for (int num = 0; num < size; num++){
		if (a[num] == i){
			return 1;
		}
	}
	return 0;
}

void shuffle(struct song_node **library, int size){
	int numbers[size];
	int siz = 0;
	int row, b;
	for (b = 0; b<size; b++){
		numbers[b] = -1;
	}
	int a[27];
	for (b = 0; b<27; b++){
		a[b] = sized(library[b]);
	}
  struct song_node *list = NULL;
	struct song_node *song;
	while (siz<size){
		int random = (rand() % size_library(library));
		if (contains(numbers, size, random)){
			continue;
		}
		else{
			numbers[siz] = random;
		}
		row = 0;
		for (b = 0; b<27; b++){
			if (random - a[b] < 0){
				break;
			}
			random -= a[b];
			row++;
		}
		song = &library[row][0];
		for (random>0; random--;){
			song = song->next;
		}
		list = insert_front(list, song->artist, song->song);
		siz++;
	}
  print_list(list);
  free (list);
}

struct song_node ** free_library(struct song_node **library){
	for (int a = 0; a<27; a++){
		library[a] = free_list(library[a]);
	}
	return library;
}
