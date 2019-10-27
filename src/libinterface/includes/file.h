#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../libknapsack/includes/knapsack.h"


int get_lines_file(char *str);
void read_from_file(tuple_t **arr, int *qtdItems, char *str);

#endif