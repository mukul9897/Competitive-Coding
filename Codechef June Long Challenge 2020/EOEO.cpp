#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
const ll M=1e9+7;
const ll inf=1e18+5;
using namespace std;
void fast(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
}

void solve(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if((n & (n-1))==0) 
		    cout<<"0\n";
		else if(n%2==1) 
		    cout<<(n-1)/2<<"\n";
		else{
			ll c=1,x=n;
			while(x%2!=1){
				c*=2;
				x/=2;
			}
			ll count=0;
			if(n%4==0){
			    cout<<(n/(2*c))<<"\n";
			}
			else 
			    cout<<n/4<<"\n";
		}
	}
 }
int main(){
	fast();
	solve();
	return 0;
}

