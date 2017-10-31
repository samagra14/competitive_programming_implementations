#include <iostream>
#include<stdio.h>
using namespace std;

//A util function to get the middle position from the ends
int getMid(int s, int e ){ return s+(e-s)/2;}

// a recursive function to build the segment tree for array[begin...end]
//st represents segment tree and currentIndex is the present index
int constructSegmentTreeUtility(int arr[],int begin, int end,int* st,int currentIndex){
  if(begin == end) // basecase for the recursion
  {// if there is only one element in the array then store it in the current index and return the value
    st[currentIndex] = arr[begin];
    return arr[begin];
  }
  // if there are further elements then construct the left abnd right subTree and then store it in the segment tree and
  // then return the node value
  st[currentIndex] = constructSegmentTreeUtility(arr,begin,getMid(begin,end),st,(currentIndex<<1)+1)
                      + constructSegmentTreeUtility(arr,getMid(begin,end)+1,end,st,(currentIndex+1)<<1);
  return st[currentIndex];
}

//The below function allocates memory for the segment tree and calls the constructSegmentTreeUtility to build a segment tree
int * constructST(int arr[],int n){
  //height of the segment tree
  int* st = new int[n<<1];
  //Fill the allocated memory and build a segment tree
  constructSegmentTreeUtility(arr,0,n-1,st,0);
  //return the constructed segment tree
  return st;
}

//the below function is used to get the sum of a given query segment.....
//st ===>pointer to segment tree
//
int getSumUtil(int* st,int ss,int se,int qs,int qe,int currentIndex){
  if (qs<=ss&&qe>=se) {
    /* code */
    return st[currentIndex];
  }
  if (se<qs||ss>qe) {
    /* code */
    return 0;
  }
  //if a part of this sum overlaps the given util
  int mid = getMid(ss,se);
  return getSumUtil(st,ss,mid,qs,qe,(currentIndex<<1)+1) +
         getSumUtil(st,mid+1,se,qs,qe,(currentIndex+1)<<1);
}
//this function returns the sum of element6s in a given query range
int getSum(int *st,int n, int qs, int qe){
  return getSumUtil(st,0,n-1,qs,qe,0);
}
//utility function to update the value in the segment tree
void updateValueUtil(int*st,int ss,int se,int i, int diff,int currentIndex){
  if(i<ss||i>se){
    return;
  }
  st[currentIndex]+=diff;
  if (se!=ss) {
    /* code */

  int mid = getMid(ss,se);
  updateValueUtil(st,ss,mid,i,diff,(currentIndex<<1)+1);
  updateValueUtil(st,mid+1,se,i,diff,(currentIndex+1)<<1);
}
}

//This function updates the value
void updateValue(int*st,int arr[],int n, int i, int newVal){
  int diff = newVal-arr[i];
  arr[i] = newVal;
  updateValueUtil(st,0,n-1,i,diff,0);
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    int *st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
            getSum(st,n, 1, 3));

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(st,arr, n, 1, 10);

    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
             getSum(st,n,1, 3));
    return 0;
}
//achhi code h bhai,   .... shirt chahiye 
