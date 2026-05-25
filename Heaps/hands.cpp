#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize !=0) return false;
        map<int,int>freq;
        for(int card: hand){
            freq[card]++;
        }
        while(!freq.empty()){
            int start = freq.begin()->first;
            for(int x = start; x<start+groupSize; x++){
                if(!freq.count(x)) return false;
                freq[x]--;
                if(freq[x] == 0) freq.erase(x);
            }
        }
        return true;
    }
};