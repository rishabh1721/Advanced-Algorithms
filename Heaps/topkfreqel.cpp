#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
#include<algorithm>

class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {

        unordered_map<int,int> freq;

        for(int n : arr)
            freq[n]++;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(auto &entry : freq){

            int number = entry.first;
            int count = entry.second;

            pq.push({count, number});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};