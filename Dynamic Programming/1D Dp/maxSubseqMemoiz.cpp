#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int func(int ind , vector<int>& arr,vector<int>&dp){
        if(ind ==0) return arr[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int pick = arr[ind] + func(ind-2,arr,dp);
        int notp = 0 + func(ind-1,arr,dp);
        return dp[ind] = max(pick,notp);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ind = arr.size()-1;
        vector<int>dp(n,-1);
        return func(ind,arr,dp);
        
    }
};