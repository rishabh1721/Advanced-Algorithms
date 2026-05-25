#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(char ch:s){
            mpp[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &entry: mpp){
            pq.push({entry.second,entry.first});
        }
        string res;
        while(!pq.empty()){
            int count = pq.top().first;
            char ch = pq.top().second;
            res.append(count,ch);
            pq.pop();
        }
        return res;
    }
};