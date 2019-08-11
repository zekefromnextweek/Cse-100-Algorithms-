#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void insertion(int *arr, int start, int end)//started with insertion because it was easier for me
{//also using the variables p q and r confused me so I made them start and end
  for (int j = start; j < end; j++)
  {
    int key = arr[j];
    int i = j - 1;
    while (i >= start && arr[i] > key) {
      arr[i + 1] = arr[i];
      i--;
    }
    arr[i + 1] = key;
  }
}

void Merge(int *arr, int start, int middle, int end)
{
  int leftSize = middle - start;
  int rightSize = end - middle;

  int *left = new int[leftSize];
  int *right = new int[rightSize];

  for (int i = 0; i < leftSize; i++)
  {
    left[i] = arr[start + i];
  }

  for (int j = 0; j < rightSize; j++)
  {
    right[j] = arr[middle + j];
  }

  int i = 0,j = 0;
  for (int k = start; k < end; k++)
  {
    // this makes sure  we don't go out of bounds:)
    if (i < leftSize && j >= rightSize)
    {
      for (;i < leftSize; ++i)//since i initialized i and j before i will leave that part ouy of the for loop
      {
        arr[k++] = left[i];
      }
    }
    else if (i >= leftSize && j < rightSize)
    {
      for (;j < rightSize; ++j)
      {
        arr[k++] = right[j];
      }
    }
    else if (i < leftSize && j < rightSize)
    {
      if (left[i] < right[j])
      {
        arr[k] = left[i];
        i++;
      } else{
        arr[k] = right[j];
        j++;
      }
    }
    
  }
}

void MyFunc(int *arr, int start, int end)
{
  int size = end - start;
  if (end - start >= 10)
  {
    // this does the  merge sort
    int middle= (int)((start + end)/2);
    MyFunc(arr, start, middle);
    MyFunc(arr, middle, end);
    Merge(arr, start, middle, end);
  } else {
    // this will do the insertion sort
    insertion(arr, start, end);
  }
}

int main(int argc,char **argv)
{
  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];

  // Read in the sequence
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  MyFunc(Sequence, 0, arraySize);

  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;

  // Free allocated space
  delete[] Sequence;
}










#include <iostream>
using namespace std;
int merge(int arr[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j, k;
	int L[n1];
	int R[n2];
	for (i = 0; i<n1; i++) {
		L[i] = arr[p + i];

	}
	for (j = 0; j<n2; j++) {
		R[j] = arr[q + j];

	}
	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}
