#include <iomanip>
#include <iostream>
#include <vector> 
using namespace std;

class Solution {
  public:
    int func(vector<vector<int>>& mat, int last,int day,vector<vector<int>>&dp){
        if(day == 0){
            int maxi =0;
            for(int i=0; i<=2; i++){
                if(i != last){
                    maxi = max(maxi,mat[0][i]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last] != -1) return dp[day][last];
        int maxi =0;
        for(int i=0; i<=2; i++){
            if(i != last){
            int points = mat[day][i] + func(mat,i,day-1,dp);
            maxi = max(maxi ,points);
        }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n, vector<int>(4,-1));
        int day = mat.size()-1;
        int last = 3;
        return func(mat,last,day,dp);
        
        
    }
};