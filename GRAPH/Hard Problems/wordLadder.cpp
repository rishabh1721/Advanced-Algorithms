#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        q.push({startWord,1});
        st.erase(startWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            
            if(word == targetWord) return step;
            
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};