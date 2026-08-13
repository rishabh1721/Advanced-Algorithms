#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // code here
        unordered_map<int,int>freq;
        for(int x : arr){
            freq[x]++;
        }
        for(int x : arr){
            if(freq[x] == 1){
                
             return x;
            }
        }
        return 0;
    }
};
