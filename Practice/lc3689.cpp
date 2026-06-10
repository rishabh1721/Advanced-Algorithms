#include <vector>
using namespace std;  

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = nums[0];
        int mx = nums[0];
        for(int num : nums){
            mn = min(mn,num);
            mx = max(mx,num);
        }
        return ((long long)(mx) - (long long)(mn))*k;
    }
};