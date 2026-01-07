#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
  string findLargest(vector<int> &nums)
  {
    // code here
    vector<string> arr;
    for (int x : nums)
    {
      arr.push_back(to_string(x));
    }

    sort(arr.begin(), arr.end(), [](string &a, string &b)
         { return a + b > b + a; });

    if (arr[0] == "0")
      return "0";

    string res = "";
    for (string &s : arr)
      res += s;
    return res;
  }
};