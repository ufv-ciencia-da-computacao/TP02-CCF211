#include "../../libknapsack/includes/knapsack.h"
#include "../../libinterface/includes/file.h"

#define INPUT_1 "../../input/1.txt"

int main() {
  int N, lines = get_lines_file(INPUT_1)-1;
  tuple_t *arr;

  tuple_arr_init(&arr, lines);
  read_from_file(&arr, &N, INPUT_1);

  printf("-------read from file-------\n");
  
  printf("N: %d\n", N);

  for (int i = 0; i < get_lines_file(INPUT_1)-1; i++) {
    printf("Id: %d | weight: %d\n", arr[i].id, arr[i].weight);
  }

  tuple_t *maxSubsetArr;
  int r = 4;
  tuple_arr_init(&maxSubsetArr, r);

  printf("\n-------knapsack algorithm-------\n");

  knapsack_algorithm(arr, &maxSubsetArr, lines, r);

  for (int i = 0; i < r; i++) {
    printf("Id: %d | weight: %d\n", maxSubsetArr[i].id, maxSubsetArr[i].weight);
  }

}