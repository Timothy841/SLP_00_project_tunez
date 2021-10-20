#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

int main(){
  struct song_node *song = insert_front(0, "oak", "hi");
  song = insert_front(song, "beech", "die");
  song = insert_front(song, "holly", "bye");
  print_list(song);
  return 0;
}
