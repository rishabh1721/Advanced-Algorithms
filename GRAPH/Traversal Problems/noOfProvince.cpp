#include<iostream>
#include<vector>
using namespace std;


class Solution {
    private:
         void dfs(int node, vector<vector<int>>& isConnected,vector<int>& ans,vector<int>& vis){
            vis[node] = 1;
            int n = isConnected.size();
            ans.push_back(node);
            for(int j=0; j<n;j++){
                if(!vis[j] && isConnected[node][j]==1) dfs(j,isConnected,ans,vis);
            }
         };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> ans;
        int cnt =0;
        int n = isConnected.size();
        vector<int> vis(n,0);
        int start = 1;
        for(int i=0; i<n;i++){
            if(!vis[i]){
                
                dfs(i,isConnected,ans,vis);
                cnt++;
            }
        }
        return cnt;
    }
};