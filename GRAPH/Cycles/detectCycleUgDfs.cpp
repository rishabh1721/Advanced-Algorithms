#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                if(dfs(adjNode, adj, vis, pathVis))
                    return true;
            }
            else if(pathVis[adjNode]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis))
                    return false; // cycle found
            }
        }

        return true; // no cycle
    }
};