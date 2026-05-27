#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    private:
         void bfs(int row, int col,
         vector<vector<int>>& vis,
         vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;

    q.push({row,col});
    vis[row][col] = 1;

   

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int k=-1;k<=1;k++)
        {
          for(int l=-1; l<=1; l++){
        
            int nRow = r + k;
            int nCol = c + l;

            if(nRow>=0 && nRow<n &&
               nCol>=0 && nCol<m &&
               grid[nRow][nCol]=='L' &&
               !vis[nRow][nCol])
            {
                vis[nRow][nCol] = 1;
                q.push({nRow,nCol});
         }   }
        }
    }
}
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='L'){
                    bfs(row,col,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};