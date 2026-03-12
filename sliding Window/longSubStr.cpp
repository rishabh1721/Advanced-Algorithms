#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashLen = 255;
        int hash[hashLen];
        for(int i=0; i<hashLen; ++i){
            hash[i] = -1;
        }
        int l=0,r=0,maxLen=0;
        while(r < s.size()){
            if(hash[s[r]] != -1){
                l = max(hash[s[r]]+1, l);
            }
            int len = r-l+1;
            maxLen = max(maxLen,len);
            hash[s[r]] = r;
            r++;

        }
        return maxLen;



    }
};