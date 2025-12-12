#include <iostream>
using namespace std;

int sumP(int n)
{
  if (n == 0)
  {
    return 0;
  }
  else
  {
    return n + sumP(n - 1);
  }
}
int main()
{
  cout << sumP(6);
}