#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

// // class Solution {
//   public:

//     // Function to rotate an array by d elements in counter-clockwise direction.
//     void rotateArr(vector<int>& arr, int d) {
//         // code here
//         int n = arr.size();
//         d = d%n;
//          vector<int> temp(d);
//          for(int i =0;i<d;i++){
//             temp[i] = arr[i];
//         }
//         for(int i=d ; i<n;i++){
//             arr[i-d]= arr[i];

//         }
//         for(int i=n-d;i<n;i++){
//             arr[i] = temp[i-(n-d)];
//         }
//     }
// };