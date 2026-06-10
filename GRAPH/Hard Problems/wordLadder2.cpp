#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    unordered_map<string, vector<string>> parents;
    vector<vector<string>> ans;

    void dfs(string word,
             string beginWord,
             vector<string>& path) {

        if(word == beginWord) {

            vector<string> temp = path;
            reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            return;
        }

        for(auto &par : parents[word]) {

            path.push_back(par);

            dfs(par, beginWord, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> dict(
            wordList.begin(),
            wordList.end());

        if(!dict.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        bool found = false;

        unordered_set<string> visited;

        visited.insert(beginWord);

        while(!q.empty() && !found) {

            int sz = q.size();

            unordered_set<string> levelVisited;

            for(int k=0;k<sz;k++) {

                string word = q.front();
                q.pop();

                string temp = word;

                for(int i=0;i<temp.size();i++) {

                    char original = temp[i];

                    for(char ch='a'; ch<='z'; ch++) {

                        temp[i] = ch;

                        if(!dict.count(temp))
                            continue;

                        if(!visited.count(temp)) {

                            if(!levelVisited.count(temp)) {

                                q.push(temp);
                                levelVisited.insert(temp);
                            }

                            parents[temp].push_back(word);

                            if(temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            for(auto &word : levelVisited) {
                visited.insert(word);
                dict.erase(word);
            }
        }

        if(!found)
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};