#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
    private:
        string topoSort(vector<vector<int>>&adj ,
        vector<int>&indegree,vector<bool>&present){
            queue<int>q;
            for(int i=0; i<26; i++){
                if(present[i]&&indegree[i]==0)q.push(i);
            }
            string order;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                order.push_back(node +'a');
                for(auto nbr : adj[node]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0)q.push(nbr);
                }
            }
            int totalchars = 0;
            for(bool ch: present){
                if(ch) totalchars++;
            }
            if(order.size() != totalchars) return "";
            return order;
        }
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>>adj(26);
        vector<int>indegree(26,0);
        vector<bool>present(26,false);
        
        for(auto &word:words){
            for(char ch:word){
                present[ch-'a']=true;
            }
        }
        for(int i=0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            int j=0;
            while(j < len && s1[j] == s2[j]){
                j++;
            }
            if(j==len){
                if(s1.size() > s2.size())
                    return "";
                 continue;
            }   
                int u = s1[j]-'a';
                int v = s2[j]-'a';
                adj[u].push_back(v);
                indegree[v]++;
            
        }
        return topoSort(adj,indegree,present);
        
    }
};