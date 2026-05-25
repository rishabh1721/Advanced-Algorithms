#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#include<algorithm>

class Solution {
    private:
          priority_queue<int> left;
          priority_queue<int,vector<int>,greater<int>> right;
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        vector<double> ans;

        for(int num : arr) {

            left.push(num);

            right.push(left.top());

            left.pop();

            if(right.size() > left.size()) {

                left.push(right.top());

                right.pop();

            }

            if(left.size() > right.size()) {

                ans.push_back(left.top());

            }

            else {

                ans.push_back(

                    (left.top() + right.top()) / 2.0

                );

            }

        }

        return ans;
    }
};
