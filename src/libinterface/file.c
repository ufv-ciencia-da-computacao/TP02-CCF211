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

  return lines+1;
}

void read_from_file(tuple_t **arr, int *qtdItems, char *str) {
  FILE *file = fopen(str, "r+");

  int cont = 0;

  while (!feof(file)) {
    if (cont == 0) {
      fscanf(file, "%d", qtdItems);
      cont++;
    } else {
      int id, weight;
      fscanf(file, "%d %d", &id, &weight);
      tuple_init(&((*arr)[cont-1]), id, weight);
      cont++;
    }
  }
}
