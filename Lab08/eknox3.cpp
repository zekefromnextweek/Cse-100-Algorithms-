#include <iostream>
#include<climits>
using namespace std;
int usedRod;//i made this to get rid of segmentation faults

int Rodcut(int p[], int rods[], int n)
{
	int r[n];
    	int lr[n];
    	r[0] = 0;
    	int i, j;
	i=1;
	while (i<=n){
		int q = INT_MIN;
        	int q2 = -1;
        	for (j = 0; j < i; j++){
            		if(q < p[j] + r[i-j-1]){
                		q = p[j] + r[i-j-1];
                		q2 = j;
            		}
        	}
        r[i] = q;
        lr[i] = q2 + 1;
	i++;
    	}
	for (i = n,j=0; i>0; i -= lr[i]){//while loop wasnt working so i made it into a for loop
        	rods[j++] = lr[i];
    	}
    	usedRod = j;
	return r[n];//returning s wont work for some reason
}
int main(int argc,char **argv) {
	int arraySize;
 	int *Sequence;
	int s2[arraySize];//sequence 2
  	cin >> arraySize;
  	Sequence = new int[arraySize];
  	for (int i=0; i<arraySize; i++)
    		cin >> Sequence[i];
      	cout <<Rodcut(Sequence,s2,arraySize)<<endl;
	for (int i=0;i<usedRod;i++)
		cout<<s2[i]<<" ";
	cout<<"-1";
	cout<<endl;
  	delete[] Sequence;
}
