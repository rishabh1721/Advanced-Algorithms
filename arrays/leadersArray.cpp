#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int leaders(vector<int> arr)
{
  int n = arr.size();
  int maxi = INT_MIN;
  for (int i = n - 1; i >= 0; i--)
  {
    if (arr[i] >= maxi)
    {
      cout << arr[i] << " ";
      maxi = arr[i];
    }
  }
  return 0;
}

// Example usage
int main()
{
  vector<int> arr = {16, 17, 4, 3, 5, 2};
  leaders(arr);
  return 0;
}