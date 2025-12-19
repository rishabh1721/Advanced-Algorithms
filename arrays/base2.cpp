#include <iostream>
#include <array>
using namespace std;
int main()
{
  // Define and initialize an array of doubles
  array<double, 4> arr = {3.5, 2.1, 4.7, 1.9};

  // Print the elements of the array
  cout << "Array elements: ";
  for (const auto &num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}