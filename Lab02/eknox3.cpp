#include <iostream>
using namespace std;
#define MAX_INT 2147483647
void merge(int arr[], int p, int q, int r)
{
    	int i;
	int j;
	int k=p;
    	int n1 = q - p + 1;
    	int n2 =  r - q;
    	int L[n1], R[n2];
    	for (i=0; i < n1; i++){//the book says i shold start at 1 but this doesnt work so I put it to zero and not it works :)
        	L[i] = arr[p + i];
	}
    	for (j=0; j < n2; j++){
        	R[j] = arr[q +1 + j];//not sure why the +1 is needed but the code would not work without it
    	}
	i = 0; 
    	j = 0; 
    	while (i < n1 && j < n2){
        	if (L[i] <= R[j]){
            		arr[k] = L[i];
            		i++;
        	}
        	else{
            		arr[k] = R[j];
            		j++;
        	}
	k++;
    	}
  	while (i < n1){
        	arr[k] = L[i];
        	i++;
        	k++;
    	}
    	while (j < n2){
        	arr[k] = R[j];
        	j++;
        	k++;
    	}

}
 
void  mergeSort(int arr[], int left, int right){
	if (left < right){
        	int mid = (left+right)/2;
        	mergeSort(arr, left, mid);
        	mergeSort(arr, mid+1, right);
        	merge(arr, left, mid, right);
    	}

}

int main(int argc,char **argv) {
  	int *Sequence;
  	int arraySize;
  	cin >> arraySize;
  	Sequence = new int[arraySize];
  	for ( int i=0; i<arraySize; i++ )
    		cin >> Sequence[i];
  	mergeSort(Sequence, 0, arraySize-1);
  	for(int i=0; i<arraySize; i++)
      		cout << Sequence[i] <<";";
  	// Free allocated space
  	delete[] Sequence;
}
