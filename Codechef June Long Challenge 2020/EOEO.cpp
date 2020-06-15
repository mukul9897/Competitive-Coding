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
			else cout<<n/4<<"\n";
		}
	}
 }
int main(){
	fast();
	solve();
	return 0;
}

