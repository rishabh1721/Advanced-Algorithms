#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
    //we will use 3 arrays one for visited, one for path visited and one for checking if the node is safe or not
    bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<int>&check,vector<vector<int>>& graph){
        vis[node] =1;
        pathvis[node]=1;
        //we will mark the node as unsafe until we are sure that it is safe

        check[node]=0;

        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,check,graph)==true){
                    check[node]=0;
                    return true;
                }
            }
                else if(pathvis[it]) {
                    check[node]=0;
                    return true;
                

            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
 }
 //if the node is safe then we will mark it as safe and return false
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>check(n,0);
        vector<int>safeNodes;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,check,graph);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};