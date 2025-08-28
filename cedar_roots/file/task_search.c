#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LEN 1024

char *task_search(const char *filename) {
  char *start_header = "# Tasks\n";
  char *end_header = "# Events\n";

  FILE *fp = fopen(filename, "r");
  if (!fp) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  return;
}
