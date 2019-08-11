#include <iostream> 
#include <stdlib.h> 
using namespace std;
int Max_Heap(int *arr, int size, int i){
        int largest=i;
        int right=2*i+2;//not sure why the left and right need those values but they work :)
        int left=2*i+1;
        if (left<size && arr[left]>arr[largest]){
                largest=left;

        }
        if (right<size && arr[right]>arr[largest]){
                largest=right;
        }
        if (largest!=i){
                swap(arr[i],arr[largest]);
                Max_Heap(arr,size,largest);
        }

}
int BuildHeap(int *arr, int size){
	for (int i=((size/2)-1);i>=0;i--)
		Max_Heap(arr,size,i);
}
int heapsort(int *array,int size){
	BuildHeap(array,size);
	for(int i=size-1;i>=0;i--){
		swap(array[0],array[i]);
		Max_Heap(array,i,0);
	}
}
int main(int argc,char **argv) {
  	int arraySize;
 	int *Sequence;
  	cin >> arraySize;
  	Sequence = new int[arraySize];
  	for (int i=0; i<arraySize; i++ )
    		cin >> Sequence[i];
  	heapsort(Sequence, arraySize);
  	for(int i=0; i<arraySize; i++)
      		cout << Sequence[i] << ";";
  	delete[] Sequence;
}
