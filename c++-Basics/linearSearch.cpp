#include <iostream>
using namespace std;
int main()
{
  int n, key;
  cout << "Enter the size of array ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements of array ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << "Enter the key to be searched ";
  cin >> key;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      cout << "Key found at index " << i;
      return 0;
    }
  }
  cout << "Key not found";
  return 0;
}