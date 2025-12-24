#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> hash(n+1, 0);
        for(int i=0; i<n; i++){
            hash[arr[i]]++;
        }
        int miss = -1 , rep =-1;
        for(int i=1 ; i<=n; i++){
            if(hash[i]==2)rep = i;
            else if(hash[i]==0)miss=i;
            if(rep !=-1 && miss !=-1){
                break;
            }
        }
        return{rep,miss};
    }
};