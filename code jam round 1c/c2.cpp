#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define va vector<long long int> a 
#define vb vector<long long int> b
#define M 1000000007
using namespace std;
ll t;
int isPalindrome(string str){
    int l = 0; 
    int h=str.length()-1;
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
             
            return 0; 
        } 
    } 
    return 1; 
} 
void fast(){cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);}
ll power(ll x,ul y,ll p){ll res = 1;x = x % p;if(x == 0)return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
void solve(){
	cin>>t;
	for(ll p=1;p<=t;p++){
		cout<<"Case #"<<p<<": ";
		ll u,b[10][26]={0};
		cin>>u;
		for(ll i=0;i<10000;i++){
			ll q;
			cin>>q;
			string str;
			cin>>str;
			ll count=0,n=q;
			while(n!=0){
				count++;
				n/=10;
			} 
			if(count==(int)str.length() && q!=-1){
				n=q;
				ll z=str.length()-1;
				while(n!=0){
					b[n%10][str[z]-'A']++;
					z--;
					n/=10;
				}
			}
		}
		ll c[26]={0};
		for(ll i=0;i<=9;i++){
			ll max1=INT_MIN,x=0;
			for(ll j=0;j<26;j++){
				if(b[i][j]>max1 && c[j]!=1){ max1=b[i][j]; x=j;}
				//cout<<b[i][j]<<" ";
			}
			cout<<(char)(x+'A');
			c[x]=1;
			//cout<<"\n";
		}
	
	
		cout<<"\n";
	}
 }
int main(){fast();solve();return 0;}

