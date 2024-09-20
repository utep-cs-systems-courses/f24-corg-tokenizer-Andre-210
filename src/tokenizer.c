#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// WILL DELETE LATER
int main() {
  char str[] = "tes ting    ";
  char *token = token_start(str);
  char *token1 = token_terminator(str);
  //int token2 = count_tokens(str);
  printf("Next word starts at: %s\n", token);
  printf("Word ends at: %s\n", token1);
  //printf("Number of tokens: %d\n ", token2);
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
    if (non_space_char(*str)) {
	return str;
   }
    str++;
  }
  return str;
}

/* returns a pointer terminator following *token */
char *token_terminator(char *token) {
  while (*token != '\0') {
    if (space_char(*token)) {
      return token;
    }
    token++;
  }
  return token;
}
/* counts the number of tokens in the string argument. */
int count_tokens(char *str) {
  char *temp = str;
  temp = token_start(temp);
  int count = 0;
  while (*temp) {
    if (non_space_char(*temp)) {
      count++;
    }
    temp = token_terminator(temp);
    temp = token_start(temp);
  }
  return count;
  }
