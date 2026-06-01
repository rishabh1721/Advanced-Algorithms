#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    private:
        bool bfs(int start, int V, vector<vector<int>> &adj, vector<int>&color){
            queue<int>q;
            q.push(start);
            color[start] = 0;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    if(color[it]==-1){
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]) return false;
                }
            }
            return true;
        }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V,-1);
        vector<vector<int>>adj(V);
        for(auto &e:edges){
            int u =e[0];
            int v= e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(bfs(i,V,adj,color)==false)return false;
            }
        }
        return true;
        
    }
};