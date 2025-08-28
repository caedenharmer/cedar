#ifndef DAILY_NOTE_H
#define DAILY_NOTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Create a daily markdown note with default sections.
 * The file will be named YYYY-MM-DD.md in the daily_files directory.
 */
void daily_create(void);

#endif // DAILY_NOTE_H
