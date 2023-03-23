#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_SIZE 1000
#define MAX_CMD_SIZE 1008

void search(char *search_words[], int word_count) {

  if (!word_count) {
    printf("Too few search terms");
    return;
  }

  char url[MAX_URL_SIZE] = "";
  char url_base[] = "https://www.bing.com/search?q=";
  char cmd[MAX_CMD_SIZE] = "start ";

  strcat_s(url, MAX_URL_SIZE * sizeof(char), url_base);

  strcat_s(url, MAX_URL_SIZE * sizeof(char), search_words[0]);

  for (int i = 1; i < word_count; i++) {
    strcat_s(url, MAX_URL_SIZE * sizeof(char), "+");
    strcat_s(url, MAX_URL_SIZE * sizeof(char), search_words[i]);
  }

  strcat_s(cmd, MAX_CMD_SIZE * sizeof(char), url);

  system(cmd);
}

int main(int argc, char *args[]) {

  int word_count = argc - 1;
  char *search_words[word_count];

  for (int i = 0; i < word_count; i++) {
    search_words[i] = args[i + 1];
  }

  search(search_words, word_count);
}
