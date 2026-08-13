#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
  public:
    int func(int ind , vector<int>& arr){
        if(ind ==0) return arr[ind];
        if(ind < 0) return 0;
        
        int pick = arr[ind] + func(ind-2,arr);
        int notp = 0 + func(ind-1,arr);
        return max(pick,notp);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int ind = arr.size()-1;
        return func(ind,arr);
        
    }
};

