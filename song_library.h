struct song_node ** create_library();
int find_letter(char *a);//helper
struct song_node ** add_song(struct song_node **library, char *a, char *s);
struct song_node * library_find_artist_song(struct song_node **library, char *a, char *s);
struct song_node * library_find_artist(struct song_node **library, char *a);
void library_print_list(struct song_node **library, char *a);
void print_artist_songs(struct song_node **library, char *a);
void print_library(struct song_node **library);
int size_library(struct song_node **library);//helper
int contains(int *a, int size, int i);//helper
void shuffle(struct song_node **library, int a);
struct song_node ** delete_song(struct song_node **library, char *a, char *s);
struct song_node ** free_library(struct song_node **library);
