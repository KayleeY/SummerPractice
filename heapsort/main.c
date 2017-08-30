#include <stdlib.h>
#include <stdio.h>
#include "heapsort.h"

int main() {
  int size = -1;
  scanf("%d", &size);
  if(size > 0){
    int *arr = malloc(size*sizeof(int));
    for(int i = 0; i < size;i++){
      scanf("%d",arr+i);
    }
    hsort(arr, size);
    for (int i = 0; i < size; ++i) {
      printf("%d\n",arr[i]);
    }
    free(arr);
  }
  return 0;
}
