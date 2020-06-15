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
		string s;
		cin>>s;
		ll l=s.length(),count=0;
		for(ll i=0;i<l-1;i++){
			if(s[i]!=s[i+1]){ 
				count++; 
				i++;
			}
		}
		cout<<count<<"\n";
	}
 }
int main(){
	fast();
	solve();
	return 0;
}

