///Aplication of Prime Factorization.....
/// Printing Technique of last non-zero value.....

#include<bits/stdc++.h>
using namespace std;
#define LOL ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define llu long long unsigned int
#define pf printf
#define sf scanf
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define pii pair<int ,int>
const int sz=1000010;
bool mark[sz+1];
vector<int> prime;
ll fact[sz+1];
int siz;
void init()
{
    prime.pb(2);
    ll i,j;
    mark[2]=true;
    for(i=3;i<=sz;i+=2)  mark[i]=true;
    int sq=sqrt(sz);
    for(i=3;i<=sq;i+=2)
    {
        if(mark[i]){
            for(j=i*i;j<=sz;j+=2*i)  mark[j]=false;
        }
    }

    for(i=3;i<=sz;i+=2)   if(mark[i]) prime.pb(i);
    siz=prime.size();
    for(i=0;i<siz;i++)
    {
        for(j=prime[i];j<=sz;j*=prime[i])  fact[j]=prime[i];
    }
    ll tl=1;
    fact[1]=tl;
    for(i=2;i<=sz;i++){
        if(fact[i]>0){
            tl=tl*fact[i];
            while(tl%10==0)  tl/=10;
            fact[i]=tl%10;
            tl=tl%1000;
        }
        else fact[i]=tl%10;
    }
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,x,y,sum,ct,ct1,m,l,r,x1,y1,mn,n,mx,h,sum1,p;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    init();
    while(cin>>n && n)
    {
        cout<<fact[n]<<endl;
    }

}


