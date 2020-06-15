#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
#define ppi pair<ll,ll>
ll bs(ll arr[], ll l, ll r, ll x){ 
	ll mid=0;
    if (r >= l){
		if (arr[mid] == x) return mid; 
        if (arr[mid] > x) return bs(arr, l, mid - 1, x); 
        return bs(arr, mid + 1, r, x);
    }
    return -1;
}
ll power(ll x,ll y,ll p){
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
struct pt {
    long double x, y;
    inline bool operator ==(pt a){
        return (a.x==x&&a.y==y);
    }
};
vector<vector<pt>> ans;
bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
  
bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

ll orientation(pt p, pt q, pt r) 
{ 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (ll i = 1; i < (ll)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    vector<pt> tpts;
    for (ll i = 0; i < (ll)up.size(); i++){
        tpts.push_back(up[i]);
        a.erase(std::remove(a.begin(),a.end(),up[i]),a.end());
        }
    for (ll i = down.size() - 2; i > 0; i--){
        tpts.push_back(down[i]);
        a.erase(std::remove(a.begin(),a.end(),down[i]),a.end());
        }
    vector<pt> temp = a;
    for(auto itr:temp){
        for(ll i=0;i<tpts.size();++i){
        ll x=orientation(tpts[i],tpts[(i+1)%tpts.size()],itr);
        if(!x) a.erase(std::remove(a.begin(),a.end(),itr),a.end());
        }
    }
    ans.pb(tpts);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
    int t;cin>>t;
    while(t--){
    	    ll n,q;
            cin>>n>>q;
	    vector<pt> points(n);
	    for(ll i=0;i<n;++i){
		ll u,v;
		cin>>u>>v;
		points[i].x=u;points[i].y=v;
	    }
	   vector<pt> copy=points;
	   while(copy.size()>2){
	       convex_hull(copy);
	   }
	   copy.clear();
	   while(q--){
		   ll answer=0;
		   pt P;cin>>P.x>>P.y;
		   for(auto itr:ans){
		       bool ok=false;
		       for(ll i=0;i<itr.size();++i){
			   if(!cw(itr[i],itr[(i+1)%itr.size()],P)) {
			       ok=true;break;
			   }
		       }
		       if(!ok) answer++;
		       else break;
		   }
		   cout<<answer<<endl;
	   }
	   ans.clear();	
	   points.clear();
	   }
}
