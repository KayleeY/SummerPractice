#include <stdio.h>
#include <stdlib.h>

static void merge(int *dest, int *a1, int len1, int *a2, int len2) {
  int pos1 = 0;
  int pos2 = 0;
  for(int i = 0; i < len1 + len2; ++i) {
    if (len1 == pos1) {
      dest[i] = a2[pos2];
      pos2++;
    } else if (pos2 < len2 && a2[pos2] < a1[pos1]) {
      dest[i] = a2[pos2];
      pos2++;
    } else {
      dest[i] = a1[pos1];
      pos1++;
    }
  }
}

void merge_sort(int *arr, int len) {
  if (len <= 1) {
    return;
  } 
  int llen = len / 2;
  int rlen = len - llen;
  int *left = malloc(sizeof(int) * llen);
  int *right = malloc(sizeof(int) * rlen);
  for (int i = 0; i < llen; ++i) {
    left[i] = arr[i];
  } 
  for (int j = 0; j < rlen; ++j) {
    right[j] = arr[llen + j];
  }
  merge_sort(left, llen);
  merge_sort(right, rlen);
  merge(arr, left, llen, right, rlen);
  free(left);
  free(right);
}
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
  merge_sort(arr, index);
  for(int i = 0; i < index; ++i) {
    printf("%d\n", arr[i]);
  }
}
