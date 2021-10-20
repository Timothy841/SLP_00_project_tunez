#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
	struct song_node *next;
	char artist[30];
	char song[30];
};

struct song_node * make_node(char *a, char *s){
	struct song_node *n = malloc(sizeof(struct song_node));
  strncpy(n->artist, a, (sizeof(n->artist)-1));
  strncpy(n->song, s, (sizeof(n->song)-1));
  return n;
}

struct song_node * insert_front(struct song_node *ne, char *a, char *s){
  struct song_node *n = make_node(a, s);
  n->next = ne;
  return n;
}

struct song_node * insert_alpha(struct song_node *ne, char *a, char *s){
  struct song_node *n = make_node(a, s);
	ne = compare_node(ne, n);
  n->next = ne;
  return n;
}

struct song_node * compare_node(struct song_node *list, struct song_node *node){
	while (strcmp(tolower(list->artist), tolower(node->artist)) < 0){//list is earlier than node
		if (strcmp(tolower(list->artist), tolower(node->artist)) > 0){//node is between the two in list

		}
		list = list->next;
	}
	if (strcmp(tolower(list->artist), tolower(node->artist)) > 0){//list is later than node

	}
}

void print_list(struct song_node *f){
	if (f == NULL){
		printf("nothing in list\n");
	}
	printf("artist:%s\t song:%s\n", f->artist, f->song);
	if (f->next != 0){
		print_list(f->next);
	}
}
