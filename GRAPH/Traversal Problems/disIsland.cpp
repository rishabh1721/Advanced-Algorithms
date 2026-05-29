#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
    private:
            void dfs(int row,int col,vector<vector<int>>& vis
            ,vector<vector<int>>& grid,vector<pair<int,int>>& vec
            ,int n,int m, int row0,int col0){
                vis[row][col] = 1;
                vec.push_back({row-row0,col-col0});
                int drow[] = {-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0; i<4; i++){
                    int nrow = row +drow[i];
                    int ncol = col +dcol[i];
                    if(nrow >=0 && ncol>=0 && nrow <n && ncol<m
                    && vis[nrow][ncol] ==0 && grid[nrow][ncol]==1){
                        dfs(nrow,ncol,vis,grid,vec,n,m,row0,col0);
                    }
                }
            }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                 vector<pair<int,int>>vec;

                    dfs(i,j,vis,grid,vec,n,m,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
