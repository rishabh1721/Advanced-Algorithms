#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int ans =1, cnt = 1;
        int i =1, j=0;
        while(i < n && j<n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
