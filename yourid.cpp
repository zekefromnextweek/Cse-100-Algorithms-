#include <iostream>

#define MAX_INT 2147483647

using namespace std;
  

int main(int argc,char **argv) {

  int* Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(int i=0; i<arraySize; i++)
    cin >> Sequence[i];

  // Output the sequence in the reverse order
  for(int i= arraySize -1; i >=0; i--)
    cout << Sequence[i] << ";";
    
  // Free allocated space
  delete[] Sequence;

}
