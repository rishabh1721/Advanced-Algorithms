#include <iostream>
#include <array>
#include <vector>
using namespace std;

vector<int> reaarange(vector<int> &arr, int n)
{
  vector<int> temp(n, 0);
  int posIndex = 0;
  int negIndex = 1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] >= 0)
    {
      temp[posIndex] = arr[i];
      posIndex += 2;
    }
    else
    {
      temp[negIndex] = arr[i];
      negIndex += 2;
    }
  }
  return temp;
}

int main()
{
  vector<int> arr = {-4, 3, 2, -7, 8, -2, 3, -1};
  int n = arr.size();
  vector<int> result = reaarange(arr, n);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
}