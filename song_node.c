#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
	struct *song_node next;
	char artist[30];
	char song[30];
}

struct foo * make_node(char *a, char *s){
	struct foo *n = malloc(sizeof(struct song_node));
  strncpy(n->artist, a, sizeof(n->artist)-1);
  strncpy(n->song, s, sizeof(n->song)-1);
  return n;
}

struct foo * insert_front(struct foo *ne, char *a, int s){
  struct foo *n = make_foo(a, s);
  n->next = ne;
  return n;
}

