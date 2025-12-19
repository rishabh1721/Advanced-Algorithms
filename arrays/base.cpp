#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
  // Define and initialize an array of integers
  array<int, 5> arr = {5, 2, 9, 1, 5};

  // Print the original array
  cout << "Original array: ";
  for (const auto &num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  // Sort the array
  sort(arr.begin(), arr.end());

  // Print the sorted array
  cout << "Sorted array: ";
  for (const auto &num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}