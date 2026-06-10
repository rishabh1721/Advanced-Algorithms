#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
         int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left < right){
            int width = right-left;
            int h = min(height[left],height[right]);
            ans = max(ans, width*h);

            if(height[left] < height[right]){
                left++;

            }
            else{
                right--;
            }
        }
        return ans;
    }
};