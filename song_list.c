#include "song.h"

struct song_list *create_list(char name) {
  struct song_list *song_list = malloc(sizeof(struct song_list));
  song_list->length = 0;
  song_list->name = name;
  return song_list;
}

struct song_node *put_in_list(struct song_list *song_list, struct song_node *song_node) {
  song_list->length++;
  
  if (!song_list->head)
    return song_list->head = song_node;
  
  struct song_node *iter_node = song_list->head;

  if (nodecmp(song_node, iter_node) < 0) {
    song_node->next = iter_node;
    return song_list->head = song_node;
  } 
  
  while (iter_node->next && nodecmp(song_node, iter_node) > 0)
    iter_node = iter_node->next;

  if (nodecmp(song_node, iter_node) == 0)
    return iter_node;
  song_node->next = iter_node->next;
  return iter_node->next = song_node;
}

struct song_node *rm_node(struct song_list *song_list, struct song_node *song_node) {
  struct song_node *iter_node = song_list->head;
  if (nodecmp(iter_node, song_node) == 0) { //target node is at head
    song_list->head = song_list->head->next;
    song_list->length--;
    return iter_node;
  }  
  
  while (nodecmp(iter_node->next, song_node) != 0) {
    iter_node = iter_node->next;
    if (!iter_node)
      return NULL; //target node not in list
  }

  struct song_node *old = iter_node->next;
  iter_node->next = iter_node->next->next;
  song_list->length--;
  return old;
}


struct song_node *find_node_in_list(struct song_list *song_list, struct song_node *song_node) {
  struct song_node *iter_node = song_list->head;

  while (iter_node) {
    if (nodecmp(iter_node, song_node) == 0)
      return iter_node;
    iter_node = iter_node->next;
  }

  return NULL;
}
    
char *repr_list(struct song_list *song_list) {
  if (!song_list)
    return "(null)";
  
  char *repr = malloc(64 * 512);
  sprintf(repr, "'%c'(%lu) list: [", song_list->name, song_list->length);
  struct song_node *iter_node = song_list->head;
  char *addr;
  int empty = 1;
  while (iter_node && !(empty = 0)) {
    strcat(strcat(repr, addr = repr_node(iter_node)), ", ");
    iter_node = iter_node->next;
    free(addr);
  }
  if (empty) {
    strcat(repr, "]");
  } else {
    repr[strlen(repr) - 2] = ']';
    repr[strlen(repr) - 1] = 0;
  }
  return repr;
}

void rm_list(struct song_list *song_list) {
  while (song_list->head)
    rm_node(song_list, song_list->head);
}

void free_node_recursive(struct song_node *song_node) {
  if (song_node) {
    free_node_recursive(song_node->next);
    free(song_node);
  }
}

void free_list(struct song_list *song_list) {
  free_node_recursive(song_list->head);
  free(song_list);
}


 
