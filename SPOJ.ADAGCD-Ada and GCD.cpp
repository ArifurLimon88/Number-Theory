/// https://www.spoj.com/problems/ADAGCD/

///*******TOPIC :  GCD and PrimeFactorization(Deep)

///***Two Accepted code: But code no:(2) is more faster for optimization of primeFactorization()...both code's are Accepted;

///Code: 1.

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
const int sz=1e7+100;
const int MX=1e9+100;
const ll mod=1000000007;
bool mark[sz+2];
vector<int> prime;
int mx[sz+2];
int test[sz+2];
int cnt[sz+2];
vector<int> raf;
void init()
{
    prime.pb(2);
    int i,j;
    for(i=3;i<=sz;i+=2)  mark[i]=true;
    int sq=sqrt(sz)+1;
    for(i=3;i<=sq;i+=2)
    {
        if(mark[i]){
            for(j=i*i;j<=sz;j+=2*i)   mark[j]=false;
        }
    }
    for(i=3;i<=sz;i+=2)  if(mark[i])  prime.pb(i);
}
ll bigmod(int a,int pr)
{
    if(pr==0)  return 1;
    else if(pr==1) return(a%mod);
    ll p=bigmod(a,pr/2);
    p=(p*p)%mod;
    if(pr&1) p=(p*a)%mod;
    return p;
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,len,x1,y1,mn,n,g,next;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    init();
    memset(cnt,0,sizeof cnt);
    sf("%d",&n);
    for(i=1;i<=sz;i++)   mx[i]=MX;
    for(j=1;j<=n;j++){
        sf("%d",&t);
        while(t--){
        sf("%d",&m);
        int sq=sqrt(m);
        p=m;
        int prsize=prime.size();
        for(i=0;i<prsize && prime[i]<=sq;i++){
            ct=0;
            while(m%prime[i]==0){
                m/=prime[i];
                ++ct;
            }
            if(ct>0) {
                test[prime[i]]+=ct;
                sq=sqrt(m);
                raf.pb(prime[i]);
            }
        }
        if(m>1) {
                test[m]+=1;
                raf.pb(m);
        }
        }
        sort(raf.begin(),raf.end());
        raf.erase(unique(raf.begin(),raf.end()),raf.end());
        for(auto xx: raf){
            ++cnt[xx];
            mx[xx]=min(mx[xx],test[xx]);
            test[xx]=0;
        }
        raf.clear();
        }
    ll ans=1;
    for(i=2;i<=sz;i++){
        if(cnt[i]==n && mx[i]!= MX){
            ll xx=bigmod(i,mx[i]);
            ans=(ans*xx)%mod;
        }
    }
    pf("%lld\n",ans);

}



**************************Code No:2 .......more faster for optimization of primeFactorization**********

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
const int sz=1e7+100;
const int MX=1e9+100;
const ll mod=1000000007;
int mark[sz+2];
int mx[sz+2];
int test[sz+2];
int cnt[sz+2];
vector<int> raf;
void init()
{
   int i,j,sq=sqrt(sz);
   for(i=2;i<=sz;i+=2)   mark[i]=2;
   for(i=3;i<=sz;i+=2){
    if(mark[i]==0){
        for(j=i;j<=sz;j+=i) mark[j]=i;
    }
   }
}
ll bigmod(int a,int pr)
{
    if(pr==0)  return 1;
    else if(pr==1) return(a%mod);
    ll p=bigmod(a,pr/2);
    p=(p*p)%mod;
    if(pr&1) p=(p*a)%mod;
    return p;
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,len,x1,y1,mn,n,g,next;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    init();
    memset(cnt,0,sizeof cnt);
    sf("%d",&n);
    for(i=1;i<=sz;i++)   mx[i]=MX;
    for(j=1;j<=n;j++){
        sf("%d",&t);
        while(t--){
        sf("%d",&m);
        int sq=sqrt(m);
        p=m;
        while(p>1)
        {
            next=mark[p];
            ct=0;
            while(p%next==0){
                ++ct;
                p/=next;
            }
            if(ct>0){
                test[next]+=ct;
                raf.pb(next);
            }
        }
        }
        sort(raf.begin(),raf.end());
        raf.erase(unique(raf.begin(),raf.end()),raf.end());

        for(auto xx: raf){
            ++cnt[xx];
            mx[xx]=min(mx[xx],test[xx]);
            test[xx]=0;
        }
        raf.clear();
        }
    ll ans=1;
    for(i=2;i<=sz;i++){
        if(cnt[i]==n && mx[i]!= MX){
            ll xx=bigmod(i,mx[i]);
            ans=(ans*xx)%mod;
        }
    }
    pf("%lld\n",ans);

}
