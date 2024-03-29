#include "./includes/knapsack.h"

static void tuplecpy(tuple_t **dest, tuple_t *src, int length) {
  for (int i = 0; i < length; i++) {
    tuple_init(&((*dest)[i]), src[i].weight, src[i].value);
  }
}


static int sum_weight(tuple_t *arr, int length) {
  int sum = 0;
  
  for (int i = 0; i < length; i++) {
    sum += arr[i].weight;
  }

  return sum;
}

static int sum_value(tuple_t *arr, int length) {
  int sum = 0;
  
  for (int i = 0; i < length; i++) {
    sum += arr[i].value;
  }

  return sum;
}

static void max_subset_arr(tuple_t **maxSubsetArr, tuple_t *data, int r, int knapsackSize) {
  int sumValueSubsetArr = sum_value(*maxSubsetArr, r);
  int sumValueData = sum_value(data, r);

  if( (sum_weight(data, r) <= knapsackSize && sumValueSubsetArr <= sumValueData)) {
    tuplecpy(maxSubsetArr, data, r);
  }
}

static void combination_util(tuple_t *arr, tuple_t *data, tuple_t **maxSubsetArr,
                    int start, int end,  
                    int index, int r, int knapsackSize)  {

    if (index == r) {
      max_subset_arr(maxSubsetArr, data, r, knapsackSize);
      return;
    }

    for (int i = start; i <= end &&  
        end - i + 1 >= r - index; i++)  
    {  
      data[index] = arr[i];  
      combination_util(arr, data, maxSubsetArr, i+1,
                      end, index+1, r, knapsackSize);
    }
}

void knapsack_algorithm(tuple_t *arr, tuple_t **maxSubsetArr, int n, int knapsackSize) {
  for (int i = 1; i <= knapsackSize; i++) {
    tuple_t *data = (tuple_t *) malloc(i * sizeof(tuple_t));  
    combination_util(arr, data, maxSubsetArr, 0, n-1, 0, i, knapsackSize);
    free(data);
  }
}

void tuple_init(tuple_t *tuple, int weight, int value) {
  tuple->value = value;
  tuple->weight = weight;
}

void tuple_arr_init(tuple_t **tuple, int size) {
  (*tuple) = (tuple_t*) malloc (size * sizeof(tuple_t));

  for (int i = 0; i < size; i++) {
    tuple_init(&((*tuple)[i]), 0, 0);
  }
}

void tuple_arr_free(tuple_t *tuple) {
  free(tuple);
}
