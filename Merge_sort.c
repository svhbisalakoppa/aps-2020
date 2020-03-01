//Merge sort
#include <stdio.h>
int len;
//Sorting in ascending order

void printArray(int arr[], int i, int j) {
  printf("[");

  for (int start = i; start < j; start++)
    printf("%d, ", arr[start]);

  printf("%d]", arr[j]);
}
void merge(int arr[], int i, int mid, int j) {
  printf("Left: ");
  printArray(arr, i, mid);
  printf(" Right: ");
  printArray(arr, mid + 1, j);
  printf("\n");
  int temp[len];
  int l = i;
  int r = j;
  int m = mid + 1;
  int k = l;

  while(l <= mid && m <= r) {
    if(arr[l] <= arr[m]) {
      temp[k++] = arr[l++];
    }
    else {
      temp[k++] = arr[m++];
    }
  }

  while(l <= mid)
    temp[k++] = arr[l++];

  while(m <= r) {
    temp[k++] = arr[m++];
  }

  for(int i1 = i; i1 <= j; i1++) {
    arr[i1] = temp[i1];
  }

  printf("After Merge: ");
  printArray(arr, i, j);
  printf("\n");
}
void mergesort(int arr[], int i, int j) {
   int mid = 0;
  if(i < j) {
    mid = (i + j) / 2;
    mergesort(arr, i, mid);
    mergesort(arr, mid + 1, j);
    merge(arr, i, mid, j);
  }
}
int main() {
  int i;
  printf("Enter the number of elements you want to enter for sorting :\n");
  scanf("%d",&len);
  if(len>1){
  int arr[len];
  printf("Enter the elements :\n");
  for(i=0;i<len;i++)
    scanf("%d",&arr[i]);
  printf("Initial Array: ");
  printArray(arr, 0, len - 1);
  printf("\n");
  mergesort(arr, 0, len - 1);
  }
  else
    if(len==1)
    printf("No sorting is required for one element\n");
  else
    printf("Invalid value\n");
    return 0; 
}
