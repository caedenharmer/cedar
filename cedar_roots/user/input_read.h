#ifndef READ_STRING_EXACT_H
#define READ_STRING_EXACT_H

// Reads a line from stdin, allocates exact memory for it,
// and returns a pointer to the string (must be freed by caller).
// Returns NULL on read error.
char *input_read(const char *prompt);

#endif

