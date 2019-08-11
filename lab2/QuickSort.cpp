
#include <string>
#include <iostream>
#include <stdlib.h>


using namespace std;
//I worked alone on this lab-Ezekiel Knox

int partitionplease(int arr[], int start, int stop){
	int z=arr[stop];
	int i=start-1;
	for (int j=start;j<=stop-1;j++){
		if(arr[j]<=z){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[stop]);
	return (i + 1);
}

void Zekesfunction(int *arr, int start, int stop){
	if(start<stop){
		int zeke=partitionplease(arr,start,stop);
		Zekesfunction(arr,start,zeke-1);
		Zekesfunction(arr,zeke+1,stop);
	}	
}
int main(int argc,char **argv) {

	int *mySequence;
  	int Sizeofarray;

  	cin >> Sizeofarray;

  	mySequence = new int[Sizeofarray];

  	for ( int i=0; i<Sizeofarray; i++ )
    	cin >> mySequence[i];

  	Zekesfunction(mySequence, 0,Sizeofarray-1);

  	for(int i=0; i<Sizeofarray; i++)
      		cout << mySequence[i] << endl;
		//cout<<rand();

	delete[] mySequence;
}

 
 


