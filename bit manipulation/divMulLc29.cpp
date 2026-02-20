#include <climits>
#include <cmath>

class Solution
{
public:
  int divide(int dividend, int divisor)
  {

    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;

    bool sign = (dividend < 0) ^ (divisor < 0);

    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);

    long long ans = 0;

    while (n >= d)
    {
      long long temp = d;
      long long multiple = 1;

      while ((temp << 1) <= n)
      {
        temp <<= 1;
        multiple <<= 1;
      }

      n -= temp;
      ans += multiple;
    }

    return sign ? -ans : ans;
  }
};
