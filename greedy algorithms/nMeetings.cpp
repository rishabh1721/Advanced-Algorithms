#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>>meetings;
        
        for(int i=0; i<n; i++){
            meetings.push_back({end[i],start[i]});
        }
        sort(meetings.begin(),meetings.end());
        int cnt = 1;
        int freeTime = meetings[0].first;
        for(int i=1; i<n; i++){
            int currSt = meetings[i].second;
            int currEnd = meetings[i].first;
            if(currSt > freeTime){
                cnt++;
                freeTime = currEnd;
            }
        }
        return cnt;
    }
    
};