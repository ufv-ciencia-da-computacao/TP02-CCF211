#include "../../libknapsack/includes/knapsack.h"
#include "../../libinterface/includes/file.h"

#define INPUT_1 "../../input/1.txt"

int main() {
  int N;
  tuple_t *arr;

  tuple_arr_init(&arr, get_lines_file(INPUT_1)-1);
  read_from_file(&arr, &N, INPUT_1);
  
  printf("N: %d\n", N);

  for (int i = 0; i < 10; i++) {
    printf("Id: %d | weight: %d\n", arr[i].id, arr[i].weight);
  }
}