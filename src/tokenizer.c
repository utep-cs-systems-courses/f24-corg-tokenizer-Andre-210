#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* return true if c is a whitespace character
   ('\t' or ' '), zero terminators return false */
int space_char(char c) {
  if((c == ' ' || c == '\t' ) && c != '\0') {
    return 1; // true
  }
  return 0; // false
}

/* return true if c is a non-whitespace character
   (not '\t' or ' '), zero terminators return false */
int non_space_char(char c) {
  if((c == ' ' || c == '\t' ) || c == '\0') {
    return 0; // false
  }
  return 1; // true
}

/* returns a pointer to the first character of the next
   space-separated token in zero-terminated str. return 0 if
   str does not contain any tokens */
char *token_start(char *str) {
  // traverse the string without changing pointer
  int i = 0;
  while(*(str + i)) {
    // if the current char is a letter
    if(non_space_char(*(str + i))) {
      return str + i;
    }
    i++;
  }
  return str + i;
}
/* returns a pointer terminator following *token */
char *token_terminator(char *token) {
  // traverse the string without updating the pointer
  int i = 0;
  while(*(token + i)) {
    // if the current char is a space
    if(space_char(*(token + i))) {
      return token + i;
    }
    i++;
  }
  return token + i;
}

/* counts the number of tokens in the string argument. */
int count_tokens(char *str) {
  // initialize a counter to return
  int count = 0;
  // initialize a temporary var
  char *token = str;
  // get the first token
  token =  token_start(token);
  while(*token) {
    // if a letter is reached, increment through the counter
    if(non_space_char(*token)) {
      count++;
    }
    // find the next token
    token = token_terminator(token);
    token = token_start(token);
  }
  return count;
}

/* returns a new zero-terminated string containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  /* malloc allocates memory (bytes) to hold char of size len + 1 (must take into account '\0')
     points to start of allocated memory, is necessary when size of data is unkown */
  char *copyStr = malloc((len + 1)*sizeof(char));
  // traverse the string (only up to len)
  for (int idx = 0; idx < len; idx++) {
    // coppy letter at idx to copyStr
    copyStr[idx] = inStr[idx];
  }
  // update the last idx to '\0'
  copyStr[len] = '\0';
  return copyStr;
}

/* returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str
   e.g: tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {
  // find the number of tokens
  int total = count_tokens(str);
  // make a temporary str
  char *token = str;
  /* initialize a double pointer (pointer pointing to an array of pointers), using 
     malloc to allocate memory (dynamic array)*/
  char **tokens = malloc(sizeof(char*) * (total + 1));
  // get tokens using loop
  for (int idx = 0; idx < total; idx++) {
    token = token_start(token); // get the start of a token
    char *tokenEnd = token_terminator(token); // get the end of the token
    // find the length of the token to use as a parameter for copy_str
    int length = tokenEnd - token;
    // copy the token to the current idx
    tokens[idx] = copy_str(token, length);
    // update the current token
    token = tokenEnd;
  }
  tokens[total] = '\0'; // set the array as zero terminated
  return tokens;
}

// prints all the tokens from the double pointer tokens
void print_tokens(char **tokens) {
  printf("Tokens: \n");
  int idx = 0;
  // traverse the tokens
  while(tokens[idx]) {
    printf("%s\n",tokens[idx]);
    idx++;
  }
}

// free all tokens and the vector conatining them
void free_tokens(char **tokens) {
  // traverse tokens and free
  int idx = 0;
  while (tokens[idx]) {
    free(tokens[idx]);
    idx++;
  }
}
