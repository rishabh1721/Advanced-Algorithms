#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mpp;
        int l=0, r=0, maxL=-1;
        while(r < s.size()){
            mpp[s[r]]++;
            if(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() == k){
                maxL = max(maxL, r-l+1);
            }
            r++;
        }
        return maxL;
    }
};