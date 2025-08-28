#include "daily_create.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cmark.h>

void daily_create(void) { 
  time_t t = time(NULL);
  struct tm *tm_info = localtime(&t);
  char date_str[11];
  strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm_info);

  char filename[14];
  snprintf(filename, sizeof(filename), "%s.md", date_str);
  char filepath[47];
  snprintf(filepath, sizeof(filepath), "../../cedar_branches/daily_files/%s", filename);

  FILE *file = fopen(filepath, "w");
  if (file) {
    fprintf(file, "# Tasks\n");
    fprintf(file, "# Events\n");
    fprintf(file, "# Field Notes\n");
    fclose(file);
    printf("Daily Note Created!\n");
  }
}
