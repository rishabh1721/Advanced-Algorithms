#include <vector>
#include <algorithm>
using namespace std;


class Solution {
  public:
  
    // DSU find with path compression
    int findParent(int node, vector<int> &parent) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent);
    }
  
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n = deadline.size();
        
        vector<pair<int,int>> jobs;
        
        // Step 1: Store (profit, deadline)
        for(int i = 0; i < n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Step 2: Sort by profit descending
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        
        // Step 3: Find max deadline
        int maxDead = 0;
        for(int i = 0; i < n; i++){
            maxDead = max(maxDead, deadline[i]);
        }
        
        // Step 4: Initialize DSU
        vector<int> parent(maxDead + 1);
        for(int i = 0; i <= maxDead; i++){
            parent[i] = i;
        }
        
        int countJobs = 0;
        int totalProfit = 0;
        
        // Step 5: Process jobs
        for(int i = 0; i < n; i++){
            
            int currProfit = jobs[i].first;
            int currDead = jobs[i].second;
            
            // Find latest available slot
            int availableSlot = findParent(currDead, parent);
            
            if(availableSlot > 0){
                countJobs++;
                totalProfit += currProfit;
                
                // Mark this slot as filled
                parent[availableSlot] = findParent(availableSlot - 1, parent);
            }
        }
        
        return {countJobs, totalProfit};
    }
};