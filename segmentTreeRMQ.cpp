#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

//A util function to get middle
int getMid(int s,int e){return s + (e-s)/2;}

int constructSegmentTreeUtility(int arr[],int begin,int end, int* st,int currentIndex){
  if (begin == end) {
    /* code */
    st[currentIndex] = arr[begin];
    return st[currentIndex];
  }

  int mid = getMid(begin,end);
  int tempOne = constructSegmentTreeUtility(arr, begin, mid, st, (currentIndex<<1)+1);
  int tempTwo = constructSegmentTreeUtility(arr,mid+1,end,st,((currentIndex+1)<<1));
  st[currentIndex] = tempOne>tempTwo ? tempTwo:tempOne;
  return st[currentIndex];
}

int * constructST(int arr[],int n){
  int *st = new int[n<<1];

  constructSegmentTreeUtility(arr,0,n-1,st,0);

  return st;
}

int getMinUtil(int*st,int ss,int se,int qs, int qe,int currentIndex){
  if (qs<=ss&&qe>=se) {
    /* code */
    return st[currentIndex];
  }

  if (se<qs||ss>qe) {
    /* code */
    return INT_MAX;
  }
  int mid = getMid(ss,se);
  int tempOne = getMinUtil(st,ss,mid,qs,qe,(currentIndex<<1)+1);
  int tempTwo = getMinUtil(st,mid+1,se,qs,qe,(currentIndex+1)<<1);
  return (tempOne>tempTwo ? tempTwo:tempOne);
}

int getMin(int*st,int n, int qs , int qe){
  return getMinUtil(st,0,n-1,qs,qe,0);
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    int *st = constructST(arr, n);

    int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range

    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, getMin(st, n, qs, qe));

    return 0;
}
