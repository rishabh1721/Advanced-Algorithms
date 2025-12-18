#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    // Step 1: XOR all numbers to get num1 ^ num2
    long long xor_all = 0;
    for (int num : nums)
    {
      xor_all ^= num;
    }

    // Step 2: Find rightmost set bit (differentiating bit)
    long long rightmost_bit = xor_all & (-xor_all);

    // Step 3: Partition into two groups and XOR each group
    int num1 = 0, num2 = 0;
    for (int num : nums)
    {
      if (num & rightmost_bit)
      {
        num1 ^= num; // Group with bit set
      }
      else
      {
        num2 ^= num; // Group with bit not set
      }
    }

    return {num1, num2};
  }
};
