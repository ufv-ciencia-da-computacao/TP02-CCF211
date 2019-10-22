#ifndef __KNAPSACK_H__
#define __KNAPSACK_H__

typedef struct tuple{
  int id;
  int weight;
} tuple_t;

void knapsack_algorithm(tuple_t *arr, tuple_t **maxSubsetArr, int n, int lengthSubset);


#endif