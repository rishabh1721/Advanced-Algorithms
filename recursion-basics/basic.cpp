#include <iostream>
using namespace std;

void recursive(int n)
{
  if (n == 5)
  {
    return;
  }
  else
  {
    cout << n << endl;
    recursive(n + 1);
    }
}
int main()
{
  recursive(5);
}