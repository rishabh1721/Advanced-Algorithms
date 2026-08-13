#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findmax(vector<int>&nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i > 0) take += prev2;
            int non = 0 + prev;
            int curri = max(take,non);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(findmax(temp1), findmax(temp2));

        
    }
};