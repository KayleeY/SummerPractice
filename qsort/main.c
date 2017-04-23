#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

int main() {
  int index = 0;
  int in = 0;
  int size = -1;
  int *arr;
  while (scanf("%d", &in)) {
    if(size == -1) {
      size = in;
      arr = malloc(size * sizeof(int));
    } else if (size == 0) {
      break;
    } else {
      arr[index] = in;
      index++;
      size--;
    }
  }
  quicksort(arr, index);
  for(int i = 0; i < index; ++i) {
    printf("%d\n", arr[i]);
  }
}
