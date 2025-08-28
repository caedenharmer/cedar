#include "insert_after_header.h"
#include "../user/input_read.h"
#include "daily_create.h"

#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  time_t t = time(NULL);
  struct tm *tm_info = localtime(&t);
  char date_str[11];
  strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm_info);

  char filename[14];
  snprintf(filename, sizeof(filename), "%s.md", date_str);
  char filepath[47];
  snprintf(filepath, sizeof(filepath), "../../cedar_branches/daily_files/%s", filename);

  if (access(filepath, F_OK) != 0) {
    printf("Creating daily note...\n");
    daily_create();
  }

  char *raw_task = input_read("Enter New Task: ");

  char formatted_task[1024];
  snprintf(formatted_task, sizeof(formatted_task), "- [ ] %s\n", raw_task);

  insert_after_header(
    filepath,
    "# Tasks\n",
    formatted_task
  );

  free(raw_task);
  return 0;
}
