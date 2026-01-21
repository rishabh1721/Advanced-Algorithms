class Solution
{
public:
  int isPowerOfFour(unsigned int n)
  {
    // Your code goes here
    if (n <= 0)
      return false;
    while (n % 4 == 0)
    {
      n /= 4;
    }
    return n == 1;
  }
};