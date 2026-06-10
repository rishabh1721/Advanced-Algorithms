#include <iomanip>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int f(vector<int>& height, int ind, vector<int>&dp){
        if(ind == 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int left = f(height, ind-1,dp)+ abs(height[ind]-height[ind-1]);
        int right = INT_MAX;
        if(ind > 1) right = f(height,ind-2,dp) +
        abs(height[ind]-height[ind-2]);
        
        return dp[ind] =  min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        
        vector<int> dp(n+1, -1);
        
        return f(height,n-1,dp);
        
    }
};