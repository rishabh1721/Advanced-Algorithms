#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int>& position, int m ,int mid){
        int cnt = 1;
        int last = position[0];
        for(int i=0; i<position.size();i++){
            if(position[i]-last >= mid){
                cnt++;
                last = position[i];
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& position, int m) {
      sort(position.begin(),position.end());
      int low = 0;
      int ans =0;
      int high = position.back()- position.front();
      while(low <= high){
        int mid = low + (high-low)/2;
        if(canPlace(position,m,mid)){
            ans = mid;
            low = mid+1;
        }else high = mid-1;
      }
      return ans;
    }
};