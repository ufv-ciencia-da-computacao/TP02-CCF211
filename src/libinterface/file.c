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
  fscanf(file, "%d", qtdItems);
  tuple_arr_init(arr, *qtdItems);
  for(int i=0; i < *qtdItems; i++) {
    int value, weight;
    fscanf(file, "%d %d", &weight, &value);
    tuple_init(&((*arr)[i]), weight, value);
  }
}
