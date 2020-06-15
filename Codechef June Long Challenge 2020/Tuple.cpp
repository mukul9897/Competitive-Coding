#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define va vector<long long int> a 
#define vb vector<long long int> b
const ll M = 1e9+7;
const ll inf = 1e18+5;
const ll max1=1005; 
using namespace std;
const int us=-999999999;
void fast(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main(){
	fast();
    int t;
    cin>>t;
    while(t--){
        long long int a[3],b[3],temp=0;
        cin>>a[0]>>a[1]>>a[2];
        cin>>b[0]>>b[1]>>b[2];
        long long int add[3],mul[3],rem[3]={0};
        for(int i=0;i<3;i++)
        {
            add[i]=b[i]-a[i];
            if(a[i]==0)
            {
                mul[i]=us;
            }
            else
            {
                mul[i]=b[i]/a[i];
                rem[i]=b[i]%a[i];
            }
        }


        if(a[1]==b[1] && a[0]==b[0] && a[2]==b[2])
        {
            cout<<0<<endl;
            temp=1;
        }
        else if((add[0]==0&&add[1]==0) || (add[1]==0&&add[2]==0) || (add[2]==0&&add[0]==0))
        {
            cout<<1<<endl;
            temp=1;
        }
        else if(((add[0]==add[1])&&add[2]==0) || ((add[2]==add[1])&&add[0]==0) || ((add[0]==add[2])&&add[1]==0))
        {
            cout<<1<<endl;
            temp=1;
        }
        else if((rem[0]==0&&rem[1]==0&&(mul[0]==mul[1])&&add[2]==0&&mul[0]!=us) || (rem[1]==0&&rem[2]==0&&(mul[1]==mul[2])&&add[0]==0&&mul[2]!=us) || (rem[0]==0&&rem[2]==0&&(mul[0]==mul[2])&&add[1]==0&&mul[0]!=us))
        {
            cout<<1<<endl;
            temp=1;
        }
        else if(add[0]==add[1] && add[1]==add[2])
        {
            cout<<1<<endl;
            temp=1;
        }
        else if(rem[0]==0 && rem[1]==0 && rem[2]==0 && (mul[0]==mul[1]) && (mul[1]==mul[2]) && mul[0]!=us)
        {
            cout<<1<<endl;
            temp=1;
        }
        else if(add[0]==0 || add[1]==0 || add[2]==0)
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(add[0]==add[1] || add[1]==add[2] || add[2]==add[0])
        {
            cout<<2<<endl;
            temp=1;
        }
        else if((rem[0]==0 && rem[1]==0 && mul[0]!=us && (mul[0]==mul[1])) || (rem[2]==0 && mul[1]!=us && rem[1]==0 && (mul[2]==mul[1])) || (rem[0]==0 && mul[0]!=us && rem[2]==0 && (mul[0]==mul[2])))
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((add[0]+add[1])==add[2]) || ((add[2]+add[1])==add[0]) || ((add[0]+add[2])==add[1]))
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((rem[0]==0&&rem[1]==0&&rem[2]==0)&&(mul[0]!=us&&mul[1]!=us&&mul[2]!=us)&&(((mul[0]*mul[1])==mul[2]) || ((mul[2]*mul[1])==mul[0]) || ((mul[0]*mul[2])==mul[1]))))
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((rem[2]==0)&&(mul[2]!=us)&&(b[0]==(add[1]+(a[0]*mul[2])))) || ((rem[1]==0)&&(mul[1]!=us)&&(b[0]==(add[2]+(a[0]*mul[1])))))   //b[0]
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((rem[2]==0)&&(mul[2]!=us)&&(b[1]==(add[0]+(a[1]*mul[2])))) || ((rem[0]==0)&&(mul[0]!=us)&&(b[1]==(add[2]+(a[1]*mul[0])))))   //b[1]
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((rem[0]==0)&&(mul[0]!=us)&&(b[2]==(add[1]+(a[2]*mul[0])))) || ((rem[1]==0)&&(mul[1]!=us)&&(b[2]==(add[0]+(a[2]*mul[1])))))   //b[2]
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((rem[1]==0)&&(mul[1]!=us)&&(b[0]==(mul[1]*(a[0]+add[2])))) || ((rem[2]==0)&&(mul[2]!=us)&&(b[0]==(mul[2]*(a[0]+add[1])))))
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((rem[0]==0)&&(mul[0]!=us)&&(b[1]==(mul[0]*(a[1]+add[2])))) || ((rem[2]==0)&&(mul[2]!=us)&&(b[1]==(mul[2]*(a[1]+add[0])))))
        {
            cout<<2<<endl;
            temp=1;
        }
        else if(((rem[1]==0)&&(mul[1]!=us)&&(b[2]==(mul[1]*(a[2]+add[0])))) || ((rem[0]==0)&&(mul[0]!=us)&&(b[2]==(mul[0]*(a[2]+add[1])))))
        {
            cout<<2<<endl;
            temp=1;
        }
        else if((b[1]==b[0]) && (b[2]==b[0]))
        {
            cout<<2<<endl;
            temp=1;
        }


        if(temp==0&&a[0]!=a[1])
        {
            float x,y;
            x=(((b[0]-b[1])*(1.0))/(a[0]-a[1]));
            y=(((b[1]*a[0])-(a[1]*b[0])*(1.0))/(a[0]-a[1]));
            if(x==(int)x && y==(int)y && (b[2]==((a[2]*x)+y) || b[2]==(a[2]*x) || b[2]==a[2]+y))
            {
                cout<<2<<endl;
                temp=1;
            }
        }
       
        if(temp==0&&a[2]!=a[1])
        {
            float x,y;
            x=(((b[2]-b[1])*(1.0))/(a[2]-a[1]));
            y=(((b[1]*a[2])-(a[1]*b[2])*(1.0))/(a[2]-a[1]));
            if(x==(int)x && y==(int)y && (b[0]==((a[0]*x)+y) || b[0]==(a[0]*x) || b[0]==a[0]+y))
            {
                cout<<2<<endl;
                temp=1;
            }
        }
       
       
        if(temp==0&&a[0]!=a[2])
        {
            float x,y;
            x=(((b[0]-b[2])*(1.0))/(a[0]-a[2]));
            y=(((b[2]*a[0])-(a[2]*b[0])*(1.0))/(a[0]-a[2]));
            if(x==(int)x && y==(int)y && (b[1]==((a[1]*x)+y) || b[1]==(a[1]*x) || b[1]==a[1]+y))
            {
                cout<<2<<endl;
                temp=1;
            }
        }
       
        if(temp==0 && a[0]!=a[1])
        {
            float x,y;
            x=(((b[1]*a[0])-(a[1]*b[0])*(1.0))/(b[0]-b[1]));
            y=(((b[0]-b[1])*(1.0))/(a[0]-a[1]));
            if(x==(int)x && y==(int)y && (b[2]==((a[2]+x)*y) || b[2]==(a[2]+x) || b[2]==a[2]*y))
            {
                cout<<2<<endl;
                temp=1;
            }
        }
       
        if(temp==0 && a[0]!=a[2])
        {
            float x,y;
            x=(((b[2]*a[0])-(a[2]*b[0])*(1.0))/(b[0]-b[2]));
            y=(((b[0]-b[2])*(1.0))/(a[0]-a[2]));
            if(x==(int)x && y==(int)y && (b[1]==((a[1]+x)*y) || b[1]==(a[1]+x) || b[1]==a[1]*y))
            {
                cout<<2<<endl;
                temp=1;
            }
        }
       
        if(temp==0 && a[2]!=a[1])
        {
            float x,y;
            x=(((b[1]*a[2])-(a[1]*b[2])*(1.0))/(b[2]-b[1]));
            y=(((b[2]-b[1])*(1.0))/(a[2]-a[1]));
            if(x==(int)x && y==(int)y && (b[0]==((a[0]+x)*y) || b[0]==(a[0]+x) || b[0]==a[0]*y))
            {
                cout<<2<<endl;
                temp=1;
            }
        }
       
       
       
        if(temp==0)
        {
            cout<<3<<endl;
        }
    }
}
