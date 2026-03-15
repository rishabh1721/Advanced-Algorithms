#include<vector>
using namespace std;
#include<stack>
#include<cmath>
class Solution {
  public:
    int subarrayRanges(vector<int>& nums) {
        // code here
        int n = nums.size();

        long long sumMax = 0;
        long long sumMin = 0;

        stack<int> st;

        

        for(int i = 0; i <= n; i++) {

            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])) {

                int mid = st.top();
                st.pop();

                int left;

                if(st.empty())
                    left = mid + 1;
                else
                    left = mid - st.top();

                int right = i - mid;

                sumMin += (long long)nums[mid] * left * right;
            }

            st.push(i);
        }

        while(!st.empty()) st.pop();

     

        for(int i = 0; i <= n; i++) {

            while(!st.empty() && (i == n || nums[st.top()] <= nums[i])) {

                int mid = st.top();
                st.pop();

                int left;

                if(st.empty())
                    left = mid + 1;
                else
                    left = mid - st.top();

                int right = i - mid;

                sumMax += (long long)nums[mid] * left * right;
            }

            st.push(i);
        }

        return sumMax - sumMin;
    }
};