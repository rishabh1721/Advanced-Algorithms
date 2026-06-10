#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here..as.size() ans grid[0].size()is used
        // multiple times so storing in n and m
        // and also to avoid TLE
        // as we are using bfs and we are traversing the whole grid
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<int,int>> q;


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {

                if(i==0 || j==0 || i==n-1 || j==m-1) {

                    if(grid[i][j] == 1) {

                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        // BFS

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i=0; i<4; i++) {

                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow>=0 && nRow<n &&
                   nCol>=0 && nCol<m &&
                   grid[nRow][nCol]==1 &&
                   !vis[nRow][nCol]) {

                    vis[nRow][nCol] = 1;

                    q.push({nRow,nCol});
                }
            }
        }

        int cnt = 0;

        for(int i=0; i<n; i++) {

            for(int j=0; j<m; j++) {

                if(grid[i][j]==1 &&
                   !vis[i][j]) {

                    cnt++;
                }
            }
        }

        return cnt;
    }
};