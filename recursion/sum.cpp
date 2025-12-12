#include <iostream>
using namespace std;

void sumpara(int n, int s)
{
  if (n < 1)
  {
    cout << s << endl;
    return;
  }
  else
  {
    sumpara(n - 1, s + n);
  }
}

int main()
{
  sumpara(3, 0);
}