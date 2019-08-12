#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int maxVal(int arr[], int z){
        int max=arr[0];
        for(int i=1;i<z;i++){
                if(arr[i]>max){
                        max=arr[i];
                }
        }
        return max;

}

int countSort(int** arr, int size, int k){
	int *B[size];
	int C[10];
	for(int i = 0; i<10; i++)
		C[i]= 0;
	for(int i = 0; i<size;i++)
		C[arr[i][k]]++;

	for(int i = 1; i<10; i++)
		C[i] = C[i]+C[i-1];

	for(int i = size-1; i >=0; i--){
		B[C[arr[i][k]]-1] = arr[i];
		C[arr[i][k]]--;
	}
	for(int i = 0; i<size; i++){	
		arr[i] = B[i];
	}
}
int count (int** arr, int size, int k){
	
	countSort(arr,size,k);
}

int radixSort (int** arr, int size) {  
	int i=9;
	while(i>=0)
	{
		if (i<10){
			count(arr, size, i);
			i--;
		}
		else{
			break;
		}
	}
}
int main(int argc,char **argv) {
 	int arraySize;
  	cin >> arraySize;
  	int l = 10;
  	int *array[arraySize];
  	for(int i = 0; i<arraySize; i ++)
		array[i] = new int[10];
  	for(int i = 0; i<arraySize; i++){
		for(int j = 0; j<10; j++){
		cin>>array[i][j];
		}
  	}
  	radixSort(array, arraySize); 
  	for(int i=0; i<arraySize; i++){
	for(int j = 0; j<10;j++){
		cout<<array[i][j]<<";";
	}
	cout<<endl;
      }
}

