#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_after_header(const char *filename, const char *header, const char *text_to_insert) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Failed to open file");
    return;
  }

  fseek(file, 0, SEEK_END);
  long filesize = ftell(file);
  rewind(file);

  char *buffer = malloc(filesize + 1);
  if (!buffer) {
    perror("Memory allocation failed");
    fclose(file);
    return;
  }

  fread(buffer, 1, filesize, file);
  buffer[filesize] = '\0';
  fclose(file);

  char *pos = strstr(buffer, header);
  if (!pos) {
    printf("Header not found\n");
    free(buffer);
    return;
  }

  pos += strlen(header);

  size_t newsize = filesize + strlen(text_to_insert) + 1;
  char *newbuffer = malloc(newsize);
  if (!newbuffer) {
    perror("Memory allocation failed");
    free(buffer);
    return;
  }

  size_t prefix_len = pos - buffer;
  memcpy(newbuffer, buffer, prefix_len);

  strcpy(newbuffer + prefix_len, text_to_insert);

  strcpy(newbuffer + prefix_len + strlen(text_to_insert), pos);

  file = fopen(filename, "w");
  if (!file) {
    perror("Failed to open file for writing");
    free(buffer);
    free(newbuffer);
    return;
  }
  fwrite(newbuffer, 1, strlen(newbuffer), file);
  fclose(file);

  free(buffer);
  free(newbuffer);
}
