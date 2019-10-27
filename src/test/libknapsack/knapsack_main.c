#include "../../libknapsack/includes/knapsack.h"
#include "../../libinterface/includes/file.h"

#define INPUT_1 "../../input/1.txt"

  
void combinationUtil(tuple_t *arr, tuple_t *data,  
                    int start, int end,  
                    int index, int r);  
  
// The main function that prints  
// all combinations of size r  
// in arr[] of size n. This function 
// mainly uses combinationUtil()  
void printCombination(tuple_t *arr, int n, int r)  
{  
    // A temporary array to store 
    // all combination one by one  
    tuple_t data[r];  
  
    // Print all combination using 
    // temprary array 'data[]'  
    combinationUtil(arr, data, 0, n-1, 0, r);  
}  
  
/* arr[] ---> Input Array  
data[] ---> Temporary array to  
store current combination  
start & end ---> Staring and 
Ending indexes in arr[]  
index ---> Current index in data[]  
r ---> Size of a combination to be printed */
void combinationUtil(tuple_t *arr, tuple_t *data,  
                    int start, int end,  
                    int index, int r)  
{  
    // Current combination is ready 
    // to be printed, print it  
    if (index == r)  
    {  
        for (int j = 0; j < r; j++)  
          printf("Id: %d | weight: %d\n", data[j].id, data[j].weight);
        printf("\n");  
        return;  
    }  
  
    // replace index with all possible  
    // elements. The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions  
    for (int i = start; i <= end &&  
        end - i + 1 >= r - index; i++)  
    {  
        data[index] = arr[i];  
        combinationUtil(arr, data, i+1,  
                        end, index+1, r);  
    }  
}  
  
// Driver code  
// int main()  
// {  
//     tuple_t arr[] = {
//       {1, 5},
//       {2, 6},
//       {3, 7},
//       {4, 8},
//       {1, 9},
//       {9, 0}
//     };  
//     int r = 3;  
//     int n = 6; 
//     printf("%d\n", n); 
//     printCombination(arr, n, r);  
// } 

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