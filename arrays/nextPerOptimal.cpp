#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void nextPermutation(vector<int> &arr)
  {
    // code here
    int index = -1;
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--)
    {
      if (arr[i] < arr[i + 1])
      {
        index = i;
        break;
      }
    }
    if (index == -1)
    {
      reverse(arr.begin(), arr.end());
      return;
    }
    for (int i = n - 1; i >= index; i--)
    {
      if (arr[i] > arr[index])
      {
        swap(arr[i], arr[index]);
        break;
      }
    }
    reverse(arr.begin() + index + 1, arr.end());
  }
};

// class Solution {
//   public:
//     void nextPermutation(vector<int>& arr) {
//         int n = arr.size();
//         int index = -1;

//         // Step 1: Find the breakpoint
//         for(int i = n - 2; i >= 0; i--) {
//             if(arr[i] < arr[i + 1]) {
//                 index = i;
//                 break;
//             }
//         }

//         // Step 2: If no breakpoint, reverse entire array
//         if(index == -1) {
//             reverse(arr.begin(), arr.end());
//             return;
//         }

//         // Step 3: Find next greater element and swap
//         for(int i = n - 1; i > index; i--) {
//             if(arr[i] > arr[index]) {
//                 swap(arr[i], arr[index]);
//                 break;
//             }
//         }

//         // Step 4: Reverse the suffix
//         reverse(arr.begin() + index + 1, arr.end());
//     }
// };
