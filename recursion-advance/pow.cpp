#include <vector>
using namespace std;

class Solution
{
public:
  double power(double x, int n)
  {
    // code here
    if (n == 0)
    {
      return 1;
    }
    if (n < 0)
    {
      return 1 / power(x, -(n + 1)) / x;
    }
    else if (n % 2 == 1)
    {
      return x * power(x, n - 1);
    }
    else
    {
      return power(x * x, n / 2);
    }
  }
};