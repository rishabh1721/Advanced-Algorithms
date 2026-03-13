#include <string>
#include <algorithm>
using namespace std;
#include <climits>

class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int hash[256] = {0};
        int sInd = -1;
        for(char c : t){
            hash[c]++ ;
        }
        int l=0,r=0;
        int cnt=0;
        while(r < s.size()){
            if(hash[s[r]] > 0){
                cnt++;

            }
            hash[s[r]]--;
            while(cnt == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sInd = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;

            }
            r++;
        }
        return (sInd == -1)?"":s.substr(sInd, minLen);
    }
};