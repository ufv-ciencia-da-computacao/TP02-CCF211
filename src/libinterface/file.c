#include "./includes/file.h"

int get_lines_file(char *str) {
  FILE *file = fopen(str, "r+");

  int lines = 0;

  while (!feof(file)) {
    char ch = fgetc(file);
    if(ch == '\n') {
      lines++;
    }
  }

  fclose(file);

  return lines;
}
