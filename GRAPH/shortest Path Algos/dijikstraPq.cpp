#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(vector<int>& e : edges) {
           int u = e[0];
           int v = e[1];
           int w = e[2];

            adj[u].push_back({v,w});
             adj[v].push_back({u,w});
}

        // Code here
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++){
            dist[i] = 1e9;
        }
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(dis > dist[node]) continue;
            
            for(auto it:adj[node]){
                int edgeWt = it.second;
                int adjNode = it.first;
                
                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis+edgeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
        
    }
};