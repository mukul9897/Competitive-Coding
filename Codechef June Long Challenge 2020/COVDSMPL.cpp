#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
const ll M=1e9+7;
const ll inf=1e18+5;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,p,x,y;
        cin>>n>>p;
        ll a[n][n],sum=0,start=0;
        for(ll i=0;i<n;i++) 
		for(ll j=0;j<n;j++) 
			a[i][j]=0;
        cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n<<"\n";
        cin>>sum;
        for(ll i=1;i<=n/2;i++){
		for(ll j=1;j<=n;j++){
			if(j<n){ 
			    cout<<1<<" "<<i<<" "<<j+1<<" "<<n<<" "<<n<<"\n";
			    cin>>x;
				cout<<1<<" "<<i+1<<" "<<1<<" "<<n<<" "<<j<<"\n";
				cin>>y;
				ll rem=sum-(x+y);
				if(rem-start==1){
					start++;
					a[i-1][j-1]=1;
				}
			}
			else if(j==n){
				cout<<1<<" "<<i+1<<" "<<1<<" "<<n<<" "<<n<<"\n";
				cin>>x;
				ll rem=sum-x;
				if(rem-start==1){
					start++;
					a[i-1][j-1]=1;
				}
			}
		}
	}
	start=0;
	for(ll i=n;i>n/2;i--){
		for(ll j=n;j>=1;j--){
			if(j!=1){ 
			    cout<<1<<" "<<1<<" "<<1<<" "<<i<<" "<<j-1<<"\n";
			    cin>>x;
				cout<<1<<" "<<1<<" "<<j<<" "<<i-1<<" "<<n<<"\n";
				cin>>y;
				ll rem=sum-(x+y);
				if(rem-start==1){
					start++;
					a[i-1][j-1]=1;
				}
			}
			else if(j==1){
				cout<<1<<" "<<1<<" "<<1<<" "<<i-1<<" "<<n<<"\n";
				cin>>x;
				ll rem=sum-x;
				if(rem-start==1){
					start++;
					a[i-1][j-1]=1;
				}
			}
		}
	}
        cout<<2<<endl;
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++) 
		    cout<<a[i][j]<<" \n"[j==n-1];
        cin>>x;
        if(x==-1) break;
       
    }
}

