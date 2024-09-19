#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main {
  char str[] = "   Hello, world!";
  char *token = token_start(str);
  printf("Next word starts at: %s\n", token);
  return 0;
}

/* return true if c is a whitespace character
   ('\t' or ' '), zero terminators return false */
int space_char(char c) {
  if ((c == ' ' || c == '\t') && c != '\0') {
    return 1;
  }
  return 0;
}

/* return true if c is a non-whitespace character
   (not '\t' or ' '), zero terminators return false */
int non_space_char(char c) {
  if ((c != ' ' || c != '\t') && c != '\0') {
    return 1;
  }
  return 0;
}

/* returns a pointer to the first character of the next
   space-separated token in zero-terminated str. return 0 if
   str does not contain any tokens */
char *token_start(char *str){
  while (*str != '\0') {
    if (non_space_char(*str) {
	return str;
   }
    str++;
  }
  return str;
}

/*
/* returns a pointer terminator following *token */
char *token_terminator(char *token) {
    return;
}
  
/* counts the number of tokens in the string argument */
int count_tokens(char *str) {
  return;
}

/* returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  return;
}

/* returns a freshly allocated new zero-terminated vector of freshly allocated 
   space-seperated tokens from zero-terminated str

   For example, tokenize ("hello world string") would result in:
      tokens[0] = "hello"
      tokens[1] = "world
      tokens[2] = "string"
      tokens[3] = 0
*/
char **tokenize(char* str) {
   return;
}

/* prints all tokens */
void print_tokens(char **tokens) {
  return;
}

/* frees all tokens and the vector conaining them */
void free_tokens(char **tokens) {
  return;
}
