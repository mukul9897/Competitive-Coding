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
	for(ll p=1;p<=t;p++){
		//cout<<"Case #"<<p<<": ";
		ll n,k;
		cin>>n>>k;
		ll a,sum=0;
		for(ll i=0;i<n;i++){
			cin>>a;
			if(a>k) 
				sum+=abs(a-k);
		}
		cout<<sum<<"\n";
	}
 }
int main(){
	fast();
	solve();
	return 0;
}

