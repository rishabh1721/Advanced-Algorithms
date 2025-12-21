#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &mat)
    {
        // code here
        // int n = mat.size();
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1;j<n;j++){
        //         swap(mat[i][j],mat[j][i]);
        //     }
        // }
        // for(int j=0; j<n; j++){
        //     int t=0,b=0;
        //   while(t<b){
        //       swap(mat[t][j],mat[b][j]);
        //       t++;
        //       b--;
        //   }
        // }

        int n = mat.size();

        // Step 1: Transpose
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse columns
        for (int j = 0; j < n; j++)
        {
            int top = 0, bottom = n - 1;
            while (top < bottom)
            {
                swap(mat[top][j], mat[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};
