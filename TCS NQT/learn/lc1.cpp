#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
      unordered_map<int,int>mp;
      for(int i=0; i<arr.size(); i++){
        int remain = target - arr[i];
        if(mp.find(remain) != mp.end()){
            return {mp[remain], i};
        }
        mp[arr[i]] = i;
      }
      return {};
    }
};




