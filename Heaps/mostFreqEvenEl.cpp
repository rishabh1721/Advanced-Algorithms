#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;  
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num:nums){
            if(num %2 == 0)freq[num]++;
        }
        int best = 0;
        int ans = -1;
        for(auto &entry:freq){
            int num = entry.first;
            int cnt = entry.second;
            if(cnt > best){
                best = cnt;
                ans = num;
            }
            else if(cnt==best && num < ans) ans = num;
        }
        return ans;
    }
};