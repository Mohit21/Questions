#include<bits/stdc++.h>
using namespace std;

/* Template by Mohit Kumra
mohitkumra95@gmail.com */

#define mod 1000000007
#define mod1 1000000009
#define pb push_back
#define ins insert
#define ll long long
#define vll vector<ll>
#define vc vector<char>
#define vstr vector<string>
#define mpll map<ll,ll>
#define mpchl map<ch,ll>
#define mplstr map<ll,string>
#define prll pair<ll,ll>
#define prlch pair<ll,ch>
#define setll set<ll>
#define setch set<char>
#define fora(i,N) for(int i=0;i<N;i++)
#define ford(i,N) for(int i=N-1;i>=0;i--)
#define forai(i,N) for(int i=0;i<N;i++)
#define foraj(j,N) for(int j=0;j<N;j++)
#define forak(j,N) for(int k=0;k<N;k++)
#define star ll T;cin>>T;while(T--)

int numD(ll sub){
    return (sub<10?1:(sub<100?2:(sub<1000?3:(sub<10000?4:5))));
}

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b,a%b);
}

bool ok(string s , int n)
{
set < char > mset;
for(int i = 0; i < n; ++i)    {
        mset.insert(s[i]);
}
bool rekt = 1;
for(int i = 0; i < n; ++i)    {
         rekt &= s[i] == s[n - i - 1];
}
if(mset.size() >= ( (n >> 1) + (n & 1) )   && rekt)    {
      return 1;
}
return 0;
}


int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);
	star{
	    ll N;
	    cin>>N;
	    ll ans=1;
	    for(ll i=0;i<(N/2)+1;i++){
            ans=((ans)*(26-i))%mod;
	    }
	    cout<<ans%mod<<endl;
	}
return 0;
}

