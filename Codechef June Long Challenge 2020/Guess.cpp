#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t;
void solve2(ll lb,ll ub){
	ll start =lb,end=ub;
	char ans;
	ll mid=(start+end)/2;
	cout<<mid<<" ";
	cin>>ans;
	if(ans=='E') 
		return;
	else if(ans=='L'){
		ll x=(mid+1+end)/2;
        	cout<<x<<" ";
        	cin>>ans;
        	if(ans=='E') 
			return;
        	else if(ans=='L') 
			solve2(start,x-1);
        	else 
			solve2(start,mid-1);
	}
	else{
		ll x=(start+mid-1)/2;
        	cout<<x<<" ";
        	cin>>ans;
        	if(ans=='E') 
			return;
        	else if(ans=='G') 
			solve2(x+1,end);
        	else 
			solve2(mid+1,end);
	}
}
char c[4];
void solve1(ll mid,ll lb,ll ub){
    
    map<ll,ll>mp;
	ll mid1=(lb+ub)/2;
    for(ll i=0;i<4;i++){
		cout<<mid1<<" ";
		cin>>c[i];
		if(i%2==0) 
			mp[c[i]]++;
	        if(c[i]=='E') 
			return;
	        if(c[i]==c[i-1] && i>0) 
			break;
	        if(i%2==1) 
			mp[c[i]]++;
    }
    
	if(mp['L']!=mp['G']){
		if(mp['L']>mp['G']) 
			solve1(mid1,lb,mid1-1);
		else 
			solve1(mid1,mid1+1,ub);
	}
	else 
		solve1(mid1,lb,ub);
 }
int main(){
	ll n;
	
	cin>>n;
	
	ll lb=2,ub=n;
	
	if(n==1e9 || n==1e5) solve2(2,n);
	
	else{
	    
	    char b;
	    
    	ll mid=(lb+ub)/2;
    	
    	cout<<mid<<" ";
    	
    	cin>>b;
    	
    	if(b!='E') solve1(n,lb,ub);
    	
    	return 0;
    	
	}
	return 0;
}

