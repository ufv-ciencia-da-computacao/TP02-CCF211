#include "./includes/knapsack.h"

static int sum_weight(tuple_t *arr, int length) {
  int sum = 0;
  
  for (int i = 0; i < length; i++) {
    sum += arr[i].weight;
  }

  return sum;
}

static void max_subset_arr(tuple_t **maxSubsetArr, tuple_t *data, int lengthSubset) {
  if (sum_weight(*maxSubsetArr, lengthSubset) < sum_weight(data, lengthSubset)){
    *maxSubsetArr = data; 
  }
}

static void combination_util(tuple_t *arr, tuple_t *data, tuple_t **maxSubsetArr,
                    int start, int end,  
                    int index, int lengthSubset)  {  
  if (index == lengthSubset) {  
    for (int j = 0; j < lengthSubset; j++)  
      max_subset_arr(maxSubsetArr, data, lengthSubset);
    return;  
  }  
  
  for (int i = start; i <= end && end - i + 1 >= lengthSubset - index; i++) {  
    data[index] = arr[i];  
    combination_util(arr, data, maxSubsetArr, i+1,  
                    end, index+1, lengthSubset);  
  }  
}

void knapsack_algorithm(tuple_t *arr, tuple_t **maxSubsetArr, int n, int lengthSubset) {  
  tuple_t data[lengthSubset];  
  
  combinationUtil(arr, maxSubsetArr, data, 0, n-1, 0, lengthSubset);  
}  