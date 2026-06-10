#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string getLongestPal(string &s) {
        // code here
          int start = 0;
        int maxLen = 0;
        for(int i=0; i<s.size(); i++){
            int l = i, r=i;
            while(l >=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
             l = i, r=i+1;
            while(l >=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxLen);
    }
};