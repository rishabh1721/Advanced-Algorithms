#include <vector>
#include <stack>
using namespace std;

/// 
//
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {

        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // store indices

        for(int i = 0; i < n; i++){

            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            if(st.empty())
                span[i] = i + 1;
            else
                span[i] = i - st.top();

            st.push(i);
        }

        return span;
    }
};