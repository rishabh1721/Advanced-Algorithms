#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;

        queue<pair<int,int>> q;
        q.push({src, -1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjNode : adj[node]) {
                if(!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if(adjNode != parent) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Convert edge list to adjacency list
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};