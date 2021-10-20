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
  struct song_node *front = ne;
	ne = compare_node(ne, n);
	if (ne==0){
		n->next = front;//node is in front
	}
	else{//node is not in front
		if (ne->next){//node in middle
			n->next = ne->next;
		}
		else{//node is last
			n->next = 0;
		}
		ne->next = n;
	}
  return n;
}

struct song_node * compare_node(struct song_node *list, struct song_node *node){
	if (strcmp((list->artist), (node->artist)) > 0){
		return 0;//node's artist is before
	}
	else while (strcmp((list->next->artist), (node->artist)) < 0){
		list = list->next;//node's artist is after
	}
	return list;
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
