#include "../../libknapsack/includes/knapsack.h"
#include "../../libinterface/includes/file.h"

#include <time.h>

#define INPUT_10 "../../input/10.txt"
#define INPUT_50 "../../input/50.txt"
#define INPUT_80 "../../input/80.txt"
#define INPUT_100 "../../input/100.txt"

int main() {
  int C, N = get_lines_file(INPUT_50)-1;
  tuple_t *arr;

  tuple_arr_init(&arr, N);
  read_from_file(&arr, &C, INPUT_50);

  printf("-------read from file-------\n");
  
  printf("C: %d\n", C);

  for (int i = 0; i < N-1; i++) {
    printf("Weight: %d | Value: %d\n", arr[i].weight, arr[i].value);
  }  

  tuple_t *maxSubsetArr;
  tuple_arr_init(&maxSubsetArr, N);

  printf("\n-------knapsack algorithm-------\n");

  clock_t t;
  t = clock();

  knapsack_algorithm(arr, &maxSubsetArr, N, C);

  t = clock() - t; 
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("knapsack_algorithm() took %f seconds to execute \n", time_taken);

  for (int i = 0; i < N; i++) {
    if (maxSubsetArr[i].weight != 0) {
      printf("Weight: %d | Value: %d\n", maxSubsetArr[i].weight, maxSubsetArr[i].value);
    }    
  }
}
