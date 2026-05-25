#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>totalWords;
        for(int i=0; i<messages.size(); i++){
            int words = count(messages[i].begin(),messages[i].end(), ' ')+1;
            totalWords[senders[i]] += words;
        }
        string ans= "";
        int best = 0;
        for(auto &entry : totalWords){
            string sender = entry.first;
            int words = entry.second;
            if(words > best){
                best = words;
                ans = sender;

            }
            else if(words==best && sender > ans) ans = sender;
        }
        return ans;
    }
};