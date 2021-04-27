#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int sumhtpo (int n,int b[],int *i){
  int r = 0;
  while (n != 1) {
    b[(*i)++]=n;
    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }
  return r;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
int bubbleSort(int arr[], int n)
{
   int i, j,r=0;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1]){
              swap(&arr[j], &arr[j+1]);r++;}
    return r;
}
int bubbleSort2(int arr[], int n)
{
   int i, j,r=0;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] < arr[j+1]){
              swap(&arr[j], &arr[j+1]);r++;}
    return r;
}

int main(){
    int b[1000],c=0,a;
    sumhtpo(73,b,&c);
    a=bubbleSort(b,c);
    printf("%d\n",b[29]);
    return 0;
}