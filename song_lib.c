#include "song.h"

//gives the library index with a given character's artists
int to_index(char c) {
  if (c >= 97 && c <= 122)
    return c - 96;
  return 0;
}

struct song_node *put_in_lib(struct song_node *song_node) {
  char c = song_node->artist[0];
  int i = to_index(c);
  lib[i] || (lib[i] = create_list(c));
  return put_in_list(lib[i], song_node);
}

struct song_node *rm_from_lib(struct song_node *song_node) {
  int i = to_index(song_node->artist[0]);
  if (lib[i]) {
    struct song_node *old = rm_node(lib[i], song_node);
    if (lib[i]->length == 0) {
      free(lib[i]);
      lib[i] = 0;
    }
    return old;
  }   
  return NULL;
}

void put_in_lib_artist(char *artist, int num_songs, ...) {
  va_list songs;
  va_start(songs, num_songs);

  while (num_songs --> 0)
    put_in_lib(create_node(va_arg(songs, char *), artist));
  
  va_end(songs);
}

struct song_node *rand_node() {
  size_t length = 0;
  int i = 27;
  while (--i>=0)
    if (lib[i])
      length += lib[i]->length;
  int r = rand() % length;
  i = 27;
  while (--i>=0) {
    if (lib[i]) {
      r -= lib[i]->length;
      if (r<0) {
	struct song_node *iter_node = lib[i]->head;
	while (r-- + lib[i]->length >0) 
	  iter_node = iter_node->next;
	return iter_node;
      }
    }
  }
}
    

struct song_node *find_node(struct song_node *song_node) {
  int index = to_index(song_node->artist[0]);
  struct song_list *song_list = lib[index];
  if (song_list)
    return find_node_in_list(song_list, song_node);
  return NULL;
}
  
struct song_node *find_by_artist(char *artist) {
  int index = to_index(artist[0]);
  if (!lib[index])
    return NULL;
  struct song_node *iter_node = lib[index]->head;
  while (iter_node) {
    if (strcmp(iter_node->artist, artist) == 0)
      return iter_node;
    iter_node = iter_node->next;
  }
  return NULL;
}

char *repr_lib() {
  char *repr = malloc(64 * 512 * 27);
  strcpy(repr, "{");
  int i;
  char *addr;
  for (i = 0; i < 27; i++)
    if (lib[i]) {
      if (strlen(repr)>1)
	strcat(repr, "\n ");
      strcat(repr, addr = repr_list(lib[i]));
      free(addr);
    }
  return strcat(repr, "}");
}

char *repr_by_artist(char *artist) {
  struct song_node *iter_node = find_by_artist(artist);
  if (!iter_node)
    return "[]";

  char *repr = malloc(64 * 512);
  strcpy(repr, "[");
  char *addr;
  while (iter_node && strcmp(iter_node->artist, artist) == 0) {
    strcat(strcat(repr, addr = repr_node(iter_node)), ", ");
    iter_node = iter_node->next;
    free(addr);
  }

  repr[strlen(repr) - 2] = ']';
  repr[strlen(repr) - 1] = 0;
  return repr;
}

void free_lib() {
  int i;
  for (i = 0; i<27; i++)
    if (lib[i]) {
      free_list(lib[i]);
      lib[i] = 0;
    }
}

void rm_lib() {
  int i;
  for (i = 0; i<27; i++)
    if (lib[i]) {
      rm_list(lib[i]);
      lib[i] = 0;
    }
}

