#include <iostream>
#include <vector>
using namespace std;

int bs(vector<int> &nums, int low, int high, int target)
{
  if (low > high)
  {
    return -1; // Target not found
  }
  int mid = low + (high - low) / 2;
  if (nums[mid] == target)
  {
    return mid; // Target found
  }
  else if (nums[mid] < target)
  {
    return bs(nums, mid + 1, high, target); // Search in the right half
  }
  else
  {
    return bs(nums, low, mid - 1, target); // Search in the left half
  }
}