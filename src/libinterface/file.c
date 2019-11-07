#include "./includes/file.h"

void read_from_file(tuple_t **arr, int *qtdItems, char *str) {
  FILE *file = fopen(str, "r+");
  fscanf(file, "%d", qtdItems);
  tuple_arr_init(arr, *qtdItems);
  for(int i=0; i < *qtdItems; i++) {
    int value, weight;
    fscanf(file, "%d %d", &weight, &value);
    tuple_init(&((*arr)[i]), weight, value);
  }
  fclose(file);
}
