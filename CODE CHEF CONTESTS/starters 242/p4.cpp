#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numbers>
#include <iomanip>
#include <climits>
#include <bitset>
#include <numeric>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    if(a==b){
	        cout<<0<<endl;
	    }
	    // else if(__gcd(a,c) == __gcd(b,c)){
	    //     cout<<1<<endl;
	    // }
	    // else if(__gcd(a,c+1) == __gcd(b,c+1)){
	    //     cout<<2<<endl;
	    // }
	    else cout<<3<<endl;
	    
	}

}
