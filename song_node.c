#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
	if (strcasecmp(list->artist, node->artist) == 0 && strcasecmp(list->song, node->song) > 0){
		return 0;
	}
	while (strcasecmp(list->artist, node->artist) < 0){//node is more than list
		if (list->next == 0){//node is last
			return list;
		}
		else if (strcasecmp(list->next->artist, node->artist) > 0){//node is between list and node after list
			return list;
		}
		if (strcasecmp(list->next->artist, node->artist) == 0 && strcasecmp(list->next->song, node->song) > 0){//list is less than node, list->next is == to node, node->song is less than list->next->song
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
			if (strcasecmp(list->next->artist, node->artist) == 0){
				list = list->next;
			}
			return list;
		}
	}
	return list;
}

void print_list(struct song_node *f){
	if (f == NULL){
		printf("nothing in list\n");
		return;
	}
	while (f->next != 0){
		printf("artist:%s\t song:%s\t next:%p\n", f->artist, f->song, f->next);
		f = f->next;
	}
	printf("artist:%s\t song:%s\t \t next:%p\tend of list\n\n", f->artist, f->song, f->next);
}

struct song_node * find_artist_song(struct song_node *ne, char *a, char *s){
	if (ne == NULL){
		return 0;
	}
	if (strcasecmp(ne->artist, a) == 0 && strcasecmp(ne->song, s) == 0){
		return ne;
	}
	while (ne->next){
		if (strcasecmp(ne->artist, a) == 0 && strcasecmp(ne->song, s) == 0){
			return ne;
		}
		else {
			ne = ne->next;
		}
	}
	if (strcasecmp(ne->artist, a) == 0 && strcasecmp(ne->song, s) == 0){
		return ne;
	}
	return 0;
}

struct song_node * find_artist(struct song_node *ne, char *a){
	if (ne == NULL){
		return 0;
	}
	while (ne->next){
		if (strcasecmp(ne->artist, a) == 0){
			return ne;
		}
		else {
			ne = ne->next;
		}
	}
	if (strcasecmp(ne->artist, a) == 0){
		return ne;
	}
	return 0;
}

int sized(struct song_node *ne){
	if (ne == NULL){
		return 0;
	}
	int a = 1;
	while (ne->next){
		a++;
		ne = ne->next;
	}
	return a;
}

struct song_node * find_random(struct song_node *ne){
	if (ne == NULL){
		return 0;
	}
	int a = rand() % sized(ne);
	for (a>0; a--;){
		ne = ne->next;
	}
	return ne;
}

struct song_node * remove_node(struct song_node *ne, char *a, char *s){
	struct song_node *front = ne;
	if (strcasecmp(ne->artist, a) == 0 && strcasecmp(ne->song, s) == 0){//first node;
		front = front->next;
		free(ne);
		return front;
	}
	while (ne->next){
		if (strcasecmp(ne->next->artist, a) == 0 && strcasecmp(ne->next->song, s) == 0){
			struct song_node *temp = ne->next;
			ne->next = ne->next->next;
			free(temp);
			return front;
		}
		else {
			ne = ne->next;
		}
	}
	return front;
}

struct song_node * free_list(struct song_node *ne){
	if (ne == NULL){
		return 0;
	}
	while (ne->next != 0){
		struct song_node *temp = ne;
		ne = ne->next;
		free(temp);
	}
	free(ne);
	return 0;
}
