#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n, vector<int>(4,-1));
        dp[0][0] =  max(mat[0][1],mat[0][2]);
        dp[0][1] =  max(mat[0][0],mat[0][2]);
        dp[0][2] = max(mat[0][0],mat[0][1]);
        dp[0][3] =  max(mat[0][0],max(mat[0][1],mat[0][2]));
        
        for(int day = 1; day<n; day++){
            for(int last=0; last<4; last++){
                dp[day][last] =0;
                for(int task=0; task<3; task++){
                    if(task != last){
                    int point = mat[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
                }
            }
            
        }
        return dp[n-1][3];
    }
};