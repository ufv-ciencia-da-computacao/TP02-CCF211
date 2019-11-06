#include "../../libknapsack/includes/knapsack.h"
#include "../../libinterface/includes/file.h"

#include <time.h>

#define INPUT_10 "../../input/10.txt"
#define INPUT_20 "../../input/20.txt"
#define INPUT_23 "../../input/23.txt"
#define INPUT_25 "../../input/25.txt"
#define INPUT_50 "../../input/50.txt"
#define INPUT_80 "../../input/80.txt"
#define INPUT_100 "../../input/100.txt"

#define C 40

int main() {
  int N, size;
  tuple_t *arr;

  printf("-------read from file-------\n");
  
  read_from_file(&arr, &N, INPUT_25);
  
  printf("C: %d\nN: %d\n", C, N);

  for (int i = 0; i < N; i++) {
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

  printf("knapsack_algorithm() took %f seconds to execute \n\n", time_taken);

  for (int i = 0; i < N; i++) {
    if (maxSubsetArr[i].weight != 0) {
      printf("Weight: %d | Value: %d\n", maxSubsetArr[i].weight, maxSubsetArr[i].value);
    }
  }
}
