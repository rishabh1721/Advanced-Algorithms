#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newI) {
        // code here
         vector<vector<int>> res;
        int i = 0, n = intervals.size();

        while (i < n && intervals[i][1] < newI[0])
            res.push_back(intervals[i++]);

        while (i < n && intervals[i][0] <= newI[1]) {
            newI[0] = min(newI[0], intervals[i][0]);
            newI[1] = max(newI[1], intervals[i][1]);
            i++;
        }
        res.push_back(newI);

        while (i < n) res.push_back(intervals[i++]);
        return res;
    }
};