#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	    int s = min(n,m);
	    string ans = "";
	    for(int i = 0; i<s; i++){
	        if(a[i] == b[i]){
	           ans += a[i];
	            
	        }else {
	            break;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
	

}
