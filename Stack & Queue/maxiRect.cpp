#include <vector>
#include <stack>
using namespace std;

class Solution {

    private: 
         int largestRectangleArea(vector<int> &arr){
            int n = arr.size();
            stack<int> st;
            int area ;
            int maxArea = 0;
            int nse,pse;
            for(int i=0; i<n; i++){
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    int ind = st.top();
                    st.pop();
                    pse = st.empty() ? -1: st.top();
                    nse = i;
                    area = (arr[ind]) * (nse-pse-1);
                    maxArea = max(maxArea , area);
 
                }
                st.push(i);
            }
            while(!st.empty()){
                nse = n;
                int ind = st.top();
                st.pop();
                pse = st.empty()? -1: st.top();
                area = (arr[ind]) * (nse-pse-1);
                maxArea = max(maxArea , area);
            }
            return maxArea;

         }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }else{
                    heights[j]++;
                }
            }
            maxArea = max(maxArea , largestRectangleArea(heights));
        }
        return maxArea;
    }
};