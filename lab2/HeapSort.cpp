
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void MaxHeapify(int *arr, int size, int i){
	//int size;
	int largestvalue=i;
	int right=2*i+1;
	int left=2*i;
	if (left<size && arr[left]>arr[largestvalue]){
		largestvalue=left;
		
	}
	if (right<size && arr[right]>arr[largestvalue]){
		largestvalue=right;
	}
	if (largestvalue!=i){
		swap(arr[i],arr[largestvalue]);
		MaxHeapify(arr,size,largestvalue);
	}
		
}
void BuildHeap(int *arr, int size){
	//int sizeofheap=size;
	//int i=((size/2)-1);
	for (int i=((size/2)-1);i>=0;i--)
		MaxHeapify(arr,size,i);
	
}
void Zekesfunction(int *array,int size){
	//}
	BuildHeap(array,size);
	for(int i=size-1;i>=0;i--){
		swap(array[0],array[i]);
		MaxHeapify(array,i,0);
	}
	
}



int main(int argc,char **argv) {
  int arraySize;
  int *mySequence;

  cin >> arraySize;

  mySequence = new int[arraySize];
  for ( int i=0; i<arraySize; i++ )
    cin >> mySequence[i];

  Zekesfunction(mySequence, arraySize); 
  for(int i=0; i<arraySize; i++)
      cout << mySequence[i] << endl;
  delete[] mySequence;
}

