#include <iostream>
#include <climits>
using namespace std;
int maxCrossSum(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;//i set intmin to be the negative infinity value 
    for (int i = mid+1; i <= high; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
        right_sum = sum;
    }
    return left_sum + right_sum;
}
int get(int arr[], int low, int high){
 int mid;
        if (low == high){
                return arr[low];
        }
        else{
                mid = (low + high)/2;
        }
        return max(max(get(arr, low, mid), get(arr, mid+1, high)), maxCrossSum(arr, low, mid, high));

}
int MaxSubArray(int arr[], int low, int high)
{

	return get(arr,low,high);
}
int main(int argc,char **argv) {
  	int *Sequence;
  	int arraySize;
  	cin >> arraySize;
  	Sequence = new int[arraySize];
  	for ( int i=0; i<arraySize; i++ )
    		cin >> Sequence[i];
  	cout<<get(Sequence, 0, arraySize-1);
  	delete[] Sequence;

}



