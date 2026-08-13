#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
      unordered_map<int,int>mpp;
      int n = arr.size();
      for(int i =0; i<n; i++){
        int need = target-arr[i];
        if(mpp.find(need) != mpp.end()){
            return {i, mpp[need]};
        }
        mpp[arr[i]] = i;
      }
      return {};
    }
};
