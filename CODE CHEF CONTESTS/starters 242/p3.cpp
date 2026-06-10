#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int> anss(n+1,0);
	    int card = k;
	    bool front = true;
	    while(card > 0){
	        if(front){
	            for(int i=1; i<=n && card>0 ; i++){
	                anss[i] += card;
	                card--;
	            }
	        }
	            else{
	                for(int i=n; i>=1 && card>0 ; i--){
	                anss[i] += card;
	                card--;
	            }
	            }
	            
	            front = !front;
	        }
	        int ans = 0;
	        for(int i=0; i<=n; i++){
	            ans = max(ans,anss[i]);
	        }
	        cout<<ans<<endl;
	    }
	

}
