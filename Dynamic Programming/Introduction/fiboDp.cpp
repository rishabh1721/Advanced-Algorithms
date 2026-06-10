#include <iostream>
#include <vector> 
using namespace std;

int f(int n, vector<int> &dp){
  if(n <= 1) return n; // Base case: F(0) = 0, F(1) = 1
  if(dp[n] != -1) return dp[n]; // If the value is already computed, return it
  dp[n] = f(n-1, dp) + f(n-2, dp); // Compute the value and store it in dp array
  return dp[n]; // Return the computed value

}

// tabulation method

int tabulation(int n){
  vector<int> dp(n+1, -1); // Create a dp array of size n+1 and initialize with -1
  dp[0] = 0; // Base case: F(0) = 0
  dp[1] = 1; // Base case: F(1) = 1
  for(int i=2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2]; // Fill the dp array iteratively
  }
  return dp[n]; // Return the nth Fibonacci number
}

//space optimized method

int spaaceOptimized(int n){
  if(n <= 1) return n; // Base case: F(0) = 0, F(1) = 1
  int a = 0; // F(0)
  int b = 1; // F(1)
  for(int i=2; i<=n; i++){
    int c = a + b; // F(i) = F(i-1) + F(i-2)
    a = b; // Update a to F(i-1)
    b = c; // Update b to F(i)
  }
  return b; // Return the nth Fibonacci number
}

int main(){
  int n;
  cout << "Enter the value of n: ";
  cin >> n;
  vector<int> dp(n+1, -1); // Create a dp array of size n+1 and initialize with -1
  cout<<f(n,dp);
  return 0;

  



}




