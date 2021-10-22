struct song_node * make_node(char *a, char *s);
struct song_node * insert_front(struct song_node *ne, char *a, char *s);
struct song_node * insert_alpha(struct song_node *ne, char *a, char *s);
struct song_node * compare_node(struct song_node *list, struct song_node *node);
void print_list(struct song_node *f);
struct song_node * find_artist_song(struct song_node *ne, char *a, char *s);
struct song_node * find_artist(struct song_node *ne, char *a);
