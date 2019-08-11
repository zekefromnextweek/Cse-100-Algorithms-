#include <iostream>
#include<cstdlib>
using namespace std;
int partition(int arr[], int low, int high){
	int pivot = arr[high];//arr
	int i= low-1;//-1
	for (int j=low; j<=high-1; j++){
		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}
int random_partition(int arr[],int low,int high){
	int pivot;
	int z=rand();
	pivot=low+z%(high-low+1);
	swap(arr[high],arr[pivot]);
	return partition(arr,low,high);
}
int w(){
	int s;
	return s;
}
int get(int arr[], int low, int high){
 	if (low==high-10000)
	w();
	if(low<high){
        int q = partition(arr, low, high);
        get(arr, low, q - 1);
        get(arr, q + 1, high);
    	}	
}

 
int quickSort(int arr[], int low, int high) {
	
	return get(arr,low,high);
}
int main(int argc,char **argv) {
  	int arraySize;
 	int *Sequence;
  	cin >> arraySize;
  	Sequence = new int[arraySize];
  	for (int i=0; i<arraySize; i++ )
    		cin >> Sequence[i];
  	quickSort(Sequence,0 ,arraySize-1);
  	for(int i=0; i<arraySize; i++)
      		cout << Sequence[i] << ";";
  	delete[] Sequence;
}
