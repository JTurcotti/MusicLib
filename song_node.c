#include "song.h"

struct song_node *create_node(char *name, char *artist) {
  struct song_node *song_node = malloc(sizeof(struct song_node));
  strcpy(song_node->name, name);
  strcpy(song_node->artist, artist);
  return song_node;
}

int nodecmp(struct song_node *one, struct song_node *two) {
  if (strcmp(one->artist, two->artist) == 0)
    return strcmp(one->name, two->name);
  return strcmp(one->artist, two->artist);
}

char *repr_node(struct song_node *song_node) {
  if (!song_node)
    return "(null)";
  char *repr = malloc(512);
  sprintf(repr, "(%s: %s)", song_node->artist, song_node->name);
  return repr;
}
