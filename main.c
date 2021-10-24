#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_library.h"
#include "song_node.h"
int main(){
  srand(time(NULL));/*
  struct song_node *list = insert_alpha(list, "hi", "bye");
  list = insert_alpha(list, "bro", "guy");
  list = insert_alpha(list, "hi", "fly");
  list = insert_alpha(list, "bro", "die");
  list = insert_alpha(list, "hi", "lie");
  printf("Linked List Test:\n\n");
  printf("Testing Print List:\n");
  print_list(list);
  printf("Testing Find Artist_Song (returns pointer) for hi, fly: %p\n", find_artist_song(list, "hi", "fly"));
  printf("Testing Find Artist (returns pointer) for hi: %p\n", find_artist(list, "hi"));
  printf("Testing Find Random (returns pointer): %p\n\n", find_random(list));
  printf("Testing Remove Node (bro, die): \n");
  list = remove_node(list, "bro", "die");
  printf("New List:\n");
  print_list(list);
  printf("Testing Free List: \n");
  list = free_list(list);
  print_list(list);*/

  printf("\nTesting Library:\n");
  struct song_node **library = create_library();
  library = add_song(library, "tomatoes", "rejoice");
  library = add_song(library, "wrist", "cumbersome");
  library = add_song(library, "trot", "nut");
  library = add_song(library, "vest", "butter");
  library = add_song(library, "grin", "gun");
  library = add_song(library, "wasteful", "helpless");
  library = add_song(library, "wasteful", "d");
  library = add_song(library, "wasteful", "g");
  library = add_song(library, "wasteful", "a");
  library = add_song(library, "wasteful", "z");
  library = add_song(library, "wasteful", "n");
  printf("Testing Print Library:\n");
  print_library(library);
  printf("\nTesting Find Artist_Song (returns pointer) for trot, nut: %p\n", library_find_artist_song(library, "trot", "nut"));
  printf("Testing Find Artist (returns pointer) for wrist: %p\n\n", library_find_artist(library, "wrist"));
  printf("Testing Print all entries under one letter, w:\n");
  library_print_list(library, "w");
  printf("Testing Print all songs from one artist, wasteful:\n");
  print_artist_songs(library, "wasteful");
  printf("\nTesting Shuffle, 3 random songs:\n");
  shuffle(library, 3);
  printf("Testing Delete One Song, wasteful, g:\n");
  library = delete_song(library, "wasteful", "g");
  print_library(library);
  printf("\nTesting Delete Library:\n");
  library = free_library(library);
  print_library(library);
  return 0;
}
