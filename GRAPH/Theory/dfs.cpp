#include<iostream>
#include<vector>
using namespace std;
#include "graphArr.cpp"
#include "graphList.cpp"


class Solution {
    private:
         void dfs(int node,vector<vector<int>>& adj, vector<int>&ans,vector<int>&vis){
             vis[node] = 1;
             ans.push_back(node);
             for(auto it: adj[node]){
                 if(!vis[it]){
                     dfs(it,adj,ans,vis);
                 }
             }
         }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n,0);
        vector<int>ans;
        int start = 0;
         dfs(start,adj,ans,vis);
         return ans;
        
        
        
    }
};