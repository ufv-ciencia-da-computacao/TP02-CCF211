#ifndef __KNAPSACK_H__
#define __KNAPSACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tuple{
  int id;
  int weight;
} tuple_t;

void tuple_init(tuple_t *tuple, int id, int weight);
void tuple_arr_init(tuple_t **tuple, int size);
void tuple_arr_free(tuple_t **tuple);
void knapsack_algorithm(tuple_t *arr, tuple_t **maxSubsetArr, int n, int r);

#endif