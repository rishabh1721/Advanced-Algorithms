#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
     
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int prev = arr[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int take = arr[i];
            if(i > 1) take += prev2;
            int non = 0 + prev;
            int curri = max(take,non);
            prev2 = prev;
            prev = curri;
            
        }
        return prev;
        
    }
};