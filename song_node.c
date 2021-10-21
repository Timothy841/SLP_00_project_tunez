/*
    insert nodes at the front
    insert nodes in order
        alphabetical by Artist then by Song
        you should have a helper function to compare song nodes effectively.
    find and return a pointer to a node based on artist and song name
    find and return a pointer to the first song of an artist based on artist name
    Return a pointer to random element in the list.
    remove a single specified node from the list
        specified by both artist and song name.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "song_node.h"

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
		return n;
	}
	else{
		n->next = ne->next;
		ne->next = n;
	  return front;
	}
}

struct song_node * compare_node(struct song_node *list, struct song_node *node){
	if (list == NULL){
		return 0;
	}
	if (strcasecmp(list->artist, node->artist) > 0){//node is less than list
		return 0;
	}
	while (strcasecmp(list->artist, node->artist) < 0){//node is more than list
		if (list->next == 0){//node is last
			return list;
		}
		else if (strcasecmp(list->next->artist, node->artist) > 0){//node is between list and node after list
			return list;
		}
		if (strcasecmp(list->next->song, node->song) > 0){//list is less than node, list->next is == to node, node->song is less than list->next->song
			return list;
		}
		list = list->next;
	}
	if (strcasecmp(list->artist, node->artist) == 0){//artist is equal
		while (strcasecmp(list->song, node->song) < 0){//node is more than list
			if (list->next == 0){//node is last
				return list;
			}
			else if (strcasecmp(list->next->song, node->song) > 0){//node is between list and node after list
				return list;
			}
			list = list->next;
		}
	}
	return list;
}

void print_list(struct song_node *f){
	if (f == NULL){
		printf("nothing in list\n");
	}
	while (f->next != 0){
		printf("artist:%s\t song:%s\t next:%p\n", f->artist, f->song, f->next);
		f = f->next;
	}
	printf("artist:%s\t song:%s\t \t next:%pend of list\n", f->artist, f->song, f->next);
}
/*
tomatoes, rejoice
wrist, cumbersome
trot, nut
vest, butter
grin, gun
wasteful, helpless
baseball, dull
screw, air
cool, attract
kitty, wretched
strip, apparatus
numerous, cynical*/
