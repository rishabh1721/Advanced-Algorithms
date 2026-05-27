#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int orangesRot(vector<vector<int>>& grid) {
        // code here
         int n= grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int cntFresh =0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] ==1) cntFresh++;
            }
        }
        int tm =0;
        int cnt = 0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t,tm);
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                    if(nRow >=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol] ==0 && grid[nRow][nCol]==1){
                        q.push({{nRow,nCol},t+1});
                        vis[nRow][nCol] = 2;
                        cnt++;
                    }
                }
            }
            
        }
        if(cntFresh != cnt) return -1;
        return tm;
    }
};