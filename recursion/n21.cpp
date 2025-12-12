#include <iostream>
using namespace std;
void print5(int i, int n)
{
  if (i <= n)
  {
    print5(i + 1, n);
    cout << i << endl;
  }
}
int main()
{
  print5(1, 10);
}