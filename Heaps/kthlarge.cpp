#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution{
public:
int KthLargest(vector<int> &arr, int k) {

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

    for(int num : arr) {

        pq.push(num);

        if(pq.size() > k)
            pq.pop();
    }

    return pq.top();
}
};