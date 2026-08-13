#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int initialPrice = prices[0];
        int maxPrice = 0;
        for(int i=1; i<prices.size(); i++){
            int profit = prices[i]- initialPrice;
            maxPrice = max(maxPrice,profit);
            initialPrice = min(initialPrice , prices[i]);
        }
        return maxPrice;
    }
};