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
    printf("Weight: %d | Value: %d\n", arr[i].weight, arr[i].value);
  }  

  tuple_t *maxSubsetArr;
  tuple_arr_init(&maxSubsetArr, N);

  printf("\n-------knapsack algorithm-------\n");

  knapsack_algorithm(arr, &maxSubsetArr, lines, N);

  for (int i = 0; i < N; i++) {
    if (maxSubsetArr[i].weight != 0) {
      printf("Weight: %d | Value: %d\n", maxSubsetArr[i].weight, maxSubsetArr[i].value);
    }    
  }
}