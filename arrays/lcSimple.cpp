#include <iostream>
#include <vector>
using namespace std;

void moveZero(vector<int> &vec)
{
  int n = vec.size();
  vector<int> temp;
  for (int i = 0; i < n; i++)
  {
    if (vec[i] != 0)
    {
      temp.push_back(vec[i]);
    }
  }
  int m = temp.size();
  for (int i = 0; i < n - m; i++)
  {
    temp.push_back(0);
  }
  for (int i = 0; i < n; i++)
  {
    vec[i] = temp[i];
    cout << vec[i] << " ";
  }
}

int main()
{

  vector<int> vec1 = {1, 2, 0, 3, 0, 4, 0, 5};
  moveZero(vec1);
}