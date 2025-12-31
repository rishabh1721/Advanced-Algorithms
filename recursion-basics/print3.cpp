#include <iostream>
using namespace std;

void print3(int i, int n)
{
  if (i < 1)
    return;
  print3(i - 1, n);
  cout << i << " ";
}
int main()
{
  print3(10, 1);
}