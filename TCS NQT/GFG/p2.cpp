#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>


class Solution {
  public:
    void reverse(vector<int>& arr, int left, int right){
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d %= n;
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
        
    }
};