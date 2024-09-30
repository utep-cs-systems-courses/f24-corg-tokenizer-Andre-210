#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  // initialize vars
  char input[100]; // will hold user input for strings
  char selection; // will hold choice picked by user
  int id; // will hold id for item user is searching for
  char *token; // will hold tokens
  List *history = init_history(); // initialize a linked list to hold the history
  
  printf("Welcome to tokenizer! What would you like to do?\n");

  while (1) {
    printf("\nEnter 't' to tokenize a string, 'h' to get the history, 'g' to get an item, or 'q' to close the program!\n");
    scanf("\n%c", &selection);

    switch (selection) {

    // tokenize a string
    case 't':
      printf("\nEnter a string to tokenize!\n>");
      scanf(" %[^\n]", &input); // scan for user input until a new line
      char **tokens = tokenize(input); // creating tokens
      printf("\n");
      add_history(history, input); // adding to history
      print_tokens(tokens); // printing tokens
      free_tokens(tokens); // freeing tokens
      break;

    // printing history
    case 'h':
      print_history(history);
      break;

    // getting an item from history
    case 'g':
      printf("\nWhat item would you like to get (enter ID)\n");
      scanf("%d", &id);
      // if the item exists
      if (get_history(history, id) != NULL) {
	token = get_history(history, id);
      }
      // otherwise the item does not exist
      else {
	break;
      }
      char **item = tokenize(token); // tokenize the item
      printf("\nRetrieved Item:\n");
      print_tokens(item);
      break;

    // close the program
    case 'q':
      free_history(history);
      printf("\nClosing the program...\n");
      return 0;

    default:
      printf("\nError, try again...\n");
      break;
    }
  }
  return 0;
}
