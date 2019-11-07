#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libinterface/includes/file.h"
#include "libknapsack/includes/knapsack.h"

#define C 40

int main() {
  int N, size;
  tuple_t *arr;
  char name[32];
  char filename[64] = "./input/";

  printf("Digite o nome do arquivo: ");
  scanf("%s", name);

  strcat(filename, name);

  printf("\n------- reading from file -------\n");

  read_from_file(&arr, &N, filename); 

  printf("\n------- knapsack algorithm -------\n");

  tuple_t *maxSubsetArr;
  tuple_arr_init(&maxSubsetArr, N);

  clock_t t;
  t = clock();

  knapsack_algorithm(arr, &maxSubsetArr, N, C);

  t = clock() - t; 
  double time_taken = ((double)t)/CLOCKS_PER_SEC;

  printf("knapsack_algorithm() took %f seconds to execute \n\nBest subset: \n\n", time_taken);

  for (int i = 0; i < N; i++) {
    if (maxSubsetArr[i].weight != 0) {
      printf("Weight: %d | Value: %d\n", maxSubsetArr[i].weight, maxSubsetArr[i].value);
    }
  }
  printf("\n\n");

  tuple_arr_free(arr);
  tuple_arr_free(maxSubsetArr);
}
