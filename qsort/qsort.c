#include "qsort.h"

void swap(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
}

void qsort_helper(int *a, int first, int last) {
     if (last <= first) return;
     int pivot = a[first];
     int pos = last;
     for (int i = last; i > first; --i) { 
     	 if (a[i] > pivot) {
	    swap(&a[i], &a[pos]);
	    pos -= 1;
	  }
     }
     swap(&a[pos],&a[first]);
     qsort_helper(a, first, pos - 1);
     qsort_helper(a, pos + 1, last);
}

void quicksort(int *a, int len) {
     qsort_helper(a, 0, len - 1);
} 
