#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

int main(){
  struct song_node *song = insert_alpha(0, "tomatoes", "rejoice");
  song = insert_alpha(song, "wrist", "cumbersome");
  song = insert_alpha(song, "trot", "nut");
  song = insert_alpha(song, "vest", "butter");
  song = insert_alpha(song, "grin", "gun");
  song = insert_alpha(song, "wasteful", "helpless");
  song = insert_alpha(song, "wasteful", "d");
  song = insert_alpha(song, "wasteful", "g");
  song = insert_alpha(song, "wasteful", "a");
  song = insert_alpha(song, "wasteful", "z");
  song = insert_alpha(song, "wasteful", "n");
  print_list(song);
  printf("%p\n", find_artist(song, "wasteful"));
  return 0;
}
