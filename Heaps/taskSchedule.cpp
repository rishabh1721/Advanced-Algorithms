#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#include<algorithm>

class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        vector<int> freq(26,0);
        for(char task:tasks){
            freq[task-'A']++;
        }
        int maxFreq = *max_element(freq.begin(),freq.end());
        int maxCnt = 0;
        for(int f:freq){
            if(f==maxFreq) maxCnt++;
        }
        int formula = (maxFreq-1)*(K+1)+maxCnt;
        int m = tasks.size();
        return max(N,formula);
    }
};