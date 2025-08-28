#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input_read(const char *prompt) {
  char buffer[1024]; // temporary big enough for max input
  printf("%s", prompt);
  if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
    return NULL; // read error
  }

  // Remove newline if present
  buffer[strcspn(buffer, "\n")] = '\0';
  // Allocate exact size needed (+1 for null terminator)    char *str = malloc(strlen(buffer) + 1);
  char *str = malloc(strlen(buffer) + 1);
  if (!str) {
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }
  strcpy(str, buffer); // copy to allocated memory
  return str;
}
