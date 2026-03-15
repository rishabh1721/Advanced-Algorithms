#include<vector>
using namespace std;
#include<stack>
#include<cmath>


class Solution {
private:

    vector<int> findNse(vector<int>& arr){

        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> findPse(vector<int>& arr){

        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);

        for(int i = 0; i < n; i++){

            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

public:
    int sumSubMins(vector<int>& arr) {

        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);

        int mod = 1e9 + 7;
        long long sum = 0;

        for(int i = 0; i < arr.size(); i++){

            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long freq = left * right;

            sum = (sum + freq * arr[i]) % mod;
        }

        return sum;
    }
};


