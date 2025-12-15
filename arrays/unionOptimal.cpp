#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> SortedArray(vector<int> &a, vector<int> &b)
  {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> temp;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
      if (a[i] < b[j])
      {
        temp.push_back(a[i]);
        i++;
      }
      else if (b[j] < a[i])
      {
        temp.push_back(b[j]);
        j++;
      }
      else
      {
        temp.push_back(a[i]);
        i++;
        j++;
      }
    }
    return temp;
  }
};