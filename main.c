#include "song.h"


int main() {
  printf("=======LINKED LIST TESTS===========\n\n");

  int i;
    
  put_in_lib_artist("b", 3, "x", "y", "z");
  put_in_lib_artist("aa", 2, "x", "y");
  put_in_lib_artist("ab", 4, "w", "z", "y", "x");
  put_in_lib_artist("a", 1, "x");
  put_in_lib_artist("bb", 1, "x");
  put_in_lib_artist("c", 3, "x", "y", "z", "w");
  put_in_lib_artist("#a", 2, "x", "y");
  put_in_lib_artist("#b", 2, "z", "w");

  
  printf("LIBRARY USED FOR TESTING: %s\n", repr_lib());

  struct song_node *test_nodes[5];
  test_nodes[0] = create_node("x", "aa");
  test_nodes[1] = create_node("y", "aa");
  test_nodes[2] = create_node("x", "ab");
  test_nodes[3] = create_node("x", "ac");
  test_nodes[4] = create_node("x", "#a");
  
  printf("\nSELECT NODES SEARCHED FOR:\n");
  for (i = 0; i<5; i++)
     printf("Library contains %s: %s\n", repr_node(test_nodes[i]), find_node(test_nodes[i])? "YES": "NO");

  char *test_artists[5];
  test_artists[0] = "a";
  test_artists[1] = "aa";
  test_artists[2] = "aaa";
  test_artists[3] = "ab";
  test_artists[4] = "#b";
  test_artists[5] = "#c";

  printf("\nSELECT ARTISTS SEARCHED FOR:\n");
  for (i = 0; i<5; i++)
    printf("First node by %s: %s; All nodes: %s\n", test_artists[i], repr_node(find_by_artist(test_artists[i])), repr_by_artist(test_artists[i]));

  test_nodes[0] = create_node("w", "b");
  test_nodes[1] = create_node("z", "aa");
  test_nodes[2] = create_node("v", "ab");
  test_nodes[3] = create_node("x", "ac");
  test_nodes[4] = create_node("z", "#a");

  char *old_lib = repr_lib();
  
  printf("\nSELECT NODES ADDED THEN REMOVED:\n");
  for (i = 0; i<5; i++) {
    put_in_lib(test_nodes[i]);
    rm_from_lib(test_nodes[i]);
    printf("%s ", repr_node(test_nodes[i]));
  }

  printf("\nLibrary after changes:\n%s\nSame as old: %s\n", repr_lib(), strcmp(repr_lib(), old_lib) == 0? "YES": "NO");


  printf("\nREMOVING WHOLE LISTS:\n");
  rm_list(lib[1]);
  printf("Library after removing all 'a' artists:\n%s\n", repr_lib());
  rm_lib();
  printf("Library after removing everything:\n%s\n", repr_lib());


  put_in_lib_artist("a", 4, "w", "x", "y", "z");
  put_in_lib_artist("b", 2, "u", "v");

  printf("Library after restored to simpler state:\n%s\n", repr_lib());

  printf("\nRANDOMLY CHOSEN NODES:\n");
  srand(time(NULL)); 

  for (i = 0; i<12; i++)
    printf("%s ", repr_node(rand_node()));
  printf("\n");
  return 0;
}
  

