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
		ll n;
		cin>>n;
		ll a[n][n];
		if(n%2==1){
			ll sum=1;
			for(ll i=0;i<n;i++){
				for(ll j=0;j<n;j++){ a[i][j]=sum; sum++;}
			}
		}
		else {
			ll sum=1;
			for(ll i=0;i<n;i++){
				if(i%2==0){
					for(ll j=0;j<n;j++){ a[i][j]=sum; sum++;}
				}
				else{
					for(ll j=n-1;j>=0;j--){ a[i][j]=sum; sum++;}
				}
			}
		}
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++) cout<<a[i][j]<<" \n"[j==n-1];
	}
 }
int main(){
	fast();
	solve();
	return 0;
}

