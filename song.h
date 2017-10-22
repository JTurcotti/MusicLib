#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>



struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
};



struct song_list {
  struct song_node *head;
  size_t length;
  char name;
};

struct song_list *lib[27];

//===============NODE FUNCTIONS=============================
struct song_node *create_node(char *name, char *artist);
int nodecmp(struct song_node *, struct song_node *);
char *repr_node(struct song_node *);

//===============LIST FUNCTIONS==========================
struct song_list *create_list(char);

//puts node in list in order (if not already present), and returns node in list
struct song_node *put_in_list(struct song_list *, struct song_node *);

//find node (or NULL)
struct song_node *find_node_in_list(struct song_list *, struct song_node *);

//removes matching node and returns copy from list, or NULL
struct song_node *rm_node(struct song_list *, struct song_node *);
char *repr_list(struct song_list *);

//frees all nodes within a list, and the list itself
void free_list(struct song_list *);
//removes all nodes from list, but doesn't free them
void rm_list(struct song_list *);

//====================LIB FUNCTIONS=======================
//adds node and returns
struct song_node *put_in_lib(struct song_node *);
//removes matching node and returns copy from lib, or NULL
struct song_node *rm_from_lib(struct song_node *);

//adds multiple nodes with the same artist
void put_in_lib_artist(char *artist, int num_songs,  ...);

//return random node
struct song_node *rand_node();

//find node (or NULL)
struct song_node *find_node(struct song_node *);

//find first node by artist (or NULL)
struct song_node *find_by_artist(char *artist);

//list of all songs by given artist
char *repr_by_artist(char *artist);

char *repr_lib();
void free_lib();
void rm_lib();
