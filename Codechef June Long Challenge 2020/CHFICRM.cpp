#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define va vector<long long int> a 
#define vb vector<long long int> b
const ll M=1e9+7;
const ll inf=1e18+5;
using namespace std;
void fast(){cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);}
ll bs(ll arr[], ll l, ll r, ll x){ 
	ll mid=0;
    if (r >= l){
		if (arr[mid] == x) return mid; 
        if (arr[mid] > x) return bs(arr, l, mid - 1, x); 
        return bs(arr, mid + 1, r, x); 
    }
    return -1;
}
ll power(ll x,ul y,ll p){
	ll res = 1;
	x = x % p;
	if(x == 0) return 0;
	while (y > 0){
		if (y & 1) res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
		}
	return res;
}


void solve(){
	ll t;
	cin>>t;
	for(ll p=1;p<=t;p++){
		//cout<<"Case #"<<p<<": ";
		ll n;
		cin>>n;
		ll a[n],flag=0;
		map<ll,ll>mp;
		for(ll i=0;i<n;i++) cin>>a[i];
		for(ll i=0;i<n;i++){
			if(a[i]==15){
				if(mp[10]==0 && mp[5]<2){ flag=1; break;}
				else if(mp[10]!=0) mp[10]--;
				else mp[5]-=2;
			}
			if(a[i]==10){
				if(mp[5]==0){ flag=1; break;}
				else mp[5]--;
			}
			mp[a[i]]++;
		}
		if(flag==1) cout<<"NO\n";
		else cout<<"YES\n";
	}
 }
int main(){
	fast();
	solve();
	return 0;
}

