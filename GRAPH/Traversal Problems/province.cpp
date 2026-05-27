#include<iostream>
#include<vector>
using namespace std;

class Solution {
     private:
         void dfs(int node, vector<vector<int>>& adj,vector<int>& ans,vector<int>& vis){
            vis[node] = 1;
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]) dfs(it,adj,ans,vis);
            }
         };
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
         vector<int> ans;
         vector<vector<int>> adj(V);
         for(auto &e:edges){
             int u = e[0];
             int v = e[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
        int cnt =0;
        int n = edges.size();
        vector<int> vis(V,0);
        int start = 1;
        for(int i=0; i<V;i++){
            if(!vis[i]){
                
                dfs(i,adj,ans,vis);
                cnt++;
            }
        }
        return cnt;
        
    }
};


