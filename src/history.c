#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/* Linked List struct: 
   int id, char *str, struct s_Item *next, Item, struct s_Item *root 
   initialize the linked list to keep the hitory
*/
List* init_history() {
  // initialize a Linked List of unknown size (point to LL)
  List *history = (List*)malloc(sizeof(List));
  // make the linked list empty if needed
  if (history != NULL) {
    // make the root null
    history->root = NULL;
  }
  return history;
}

/* add a history item to the end of the list
  List* list - the linked list
  char* str - the string to store
*/
void add_history(List *list, char *str) {
  // initialize a new node for the Linked List of unkown size
  Item *newNode = (Item*)malloc(sizeof(Item));
  // initialize id var
  static int currId = 1;
  // check if the node is null, if so, creation failed
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }
  // find the length of the string
  int length = 0;
  while (*(str + length) != '\0' && *(str + length) != '\n') {
    length++;
  }
  // set str for the new node (size unknown so allocate memory) (an array)
  newNode->str = (char*)malloc((length + 1) * sizeof(char));
  // if the str is still null, creation failed
  if (newNode->str == NULL) {
    printf("Memory allocation failed\n");
    free(newNode);
    return;
  }
  // fill newNode str with string
  for (int idx = 0; idx < length; idx++) {
    newNode->str[idx] = str[idx];
  }
  // set the next node as null
  newNode->next = NULL;
  // if the root node is null, append new node to root
  if (list->root == NULL) {
    newNode->id = currId;
    list->root = newNode;
  }
  // otherwise the root is not null, reach the end of the linked list and append new node
  else {
    // make a dummy list
    Item *dummy = list->root;
    while (dummy->next != NULL) {
      dummy = dummy->next;
    }
    // update the id and append the new node to the linked list
    newNode->id = currId;
    dummy->next = newNode;
  }
  // update the id
  currId++;
}

/* retrieve the string stored in the node where Item->id == id
   List *list - the linked list
   int id - the id of the Item to find
*/
char *get_history(List *list, int id) {
  if (list->root == NULL || list == NULL) {
    printf("\nNothing is in the history\n");
    return NULL;
  }
  // make a dummy node
  Item *dummy = list->root;
  // traverse the Linked List
  while (dummy != NULL) {
    if (dummy->id ==id) {
      return dummy->str;
    }
    dummy = dummy->next;
  }
  printf("\nItem not found\n");
  return NULL;
}

// print history
void print_history(List *list) {
  // check if the root node/linked list is null
  if (list->root == NULL || list == NULL) {
    printf("Nothing is in the history\n");
  }
  printf("\nPrinting the History of User:\n");
  // make a dummy node
  Item *dummy = list->root;
  // traverse the linked list and print
  while (dummy != NULL) {
    if (dummy->str != NULL) {
      printf("ID: %d - Item: %s\n", dummy->id,  dummy->str);
      dummy = dummy->next;
    }
    else {
      printf("ID: %d - Item: NULL\n", dummy->id); 
    }
  }
}

// free the history of the list and the string it references
void free_history(List *list) {
  // check if the list is already empty
  if (!list) {
    return;
  }
  // initialize a node and a dummy node
  Item *node;
  Item *dummy = list->root;
  // traverse the linked list
  while (dummy != NULL) {
    node = dummy;
    /// free up the node
    free(node->str);
    free(node);
    dummy = dummy->next;
  }
  printf("\nHistory has been cleared\n");
}
