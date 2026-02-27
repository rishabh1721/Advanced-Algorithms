#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {

        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());
        
        int n = greed.size();
        int m = cookie.size();
        
        int child = 0;   // pointer for greed
        int cook = 0;    // pointer for cookie
        
        while (child < n && cook < m) {
            if (cookie[cook] >= greed[child]) {
                child++;   // child satisfied
            }
            cook++;        // move to next cookie
        }
        
        return child;  // number of satisfied children
    }
};