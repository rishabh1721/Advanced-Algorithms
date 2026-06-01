#include <iostream>
#include <vector>
using namespace std;


class Solution {
    private:
        bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj){
            vis[node]=1;
            pathVis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]){
                    if(dfs(it,vis,pathVis,adj)==true) return true;
                }
                else if(pathVis[it]==1)return true;
            }
            pathVis[node]=0;
            return false;
        }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V,0);
        vector<int>pathVis(V,0);
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            int u= e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true)return true;;
            }
        }
        return false;
        
    }
};