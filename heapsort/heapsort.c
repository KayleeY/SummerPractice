#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

struct heap {
  int *a;
  const int size;
  int len;//len will decrease by 1 when poping
};

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbledown(int *a, int i, int len) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int smallest = i;
  if (left < len && a[left] < a[i]) {
    smallest = left;
  } 
  if (right < len && a[right] < a[smallest]) {
    smallest = right;
  }
  if (smallest != i) {
    swap (a+smallest, a+i);
    bubbledown(a, smallest, len);
  }
}

void heapify(int *a, int len) {
  for (int i = (len / 2) - 1; i >= 0; i--) {
    bubbledown(a, i, len);
  }
}

int pop(int *a, int len) {
  int first = a[0];
  swap (a, a+len-1);
  bubbledown(a, 0, len-1);
  return first;
}

void hsort(int *a, int len) {
  int *array = malloc (len * sizeof(int));
  for (int i = 0; i < len; i++) {
    array[i] = a[i];
  }
  struct heap heap1 = {array,len,len};
  // heap1.a = array;
  //heap1.size = len;
  //heap1.len = len;
  heapify(heap1.a, heap1.size);
  for (int j = 0; j < heap1.size; j++) {
    a[j] = pop(heap1.a, heap1.len);
    heap1.len--;
  }
  free(array);
}
