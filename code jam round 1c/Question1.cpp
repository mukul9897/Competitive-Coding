#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define va vector<long long int> a 
const ll M=1e9+7;
const ll inf=1e18+5;
using namespace std;
ll t;
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
	cin>>t;
	for(ll p=1;p<=t;p++){
		cout<<"Case #"<<p<<": ";
		ll x,y,flag=0;
		cin>>x>>y;
		string a;
		cin>>a;
		for(ll i=0;i<(int)a.length();i++){
			if(a[i]=='E') x++;
			else if(a[i]=='W') x--;
			else if(a[i]=='N') y++;
			else y--;
			if(abs(x)+abs(y)<=i+1){ cout<<i+1; flag=1; break;}
		}
		if(flag==0) cout<<"IMPOSSIBLE";
		
		cout<<"\n";
	}
 }
int main(){
	fast();
	solve();
	return 0;
}

