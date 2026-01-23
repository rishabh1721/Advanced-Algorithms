class Solution
{
public:
  int repeatedSumOfDigits(int num)
  {
    // code here
    if (num == 0)
      return 0;
    return 1 + (num - 1) % 9;
  }
};
