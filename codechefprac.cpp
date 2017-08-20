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
#define fora1(i,M) for(int i=0;i<M;i++)
#define ford(i,N) for(int i=N-1;i>=0;i--)
#define forai(i,N) for(int i=0;i<N;i++)
#define foraj(j,N) for(int j=0;j<N;j++)
#define forak(j,N) for(int k=0;k<N;k++)
#define star ll T;cin>>T;while(T--)

int numD(ll sub){
    return (sub<10?1:(sub<100?2:(sub<1000?3:(sub<10000?4:5))));
}

inline ll gcd(ll a, ll b){
    //while(b) b ^= a ^= b ^= a %= b;
    //return a;
    return b==0 ? a : gcd(b,a%b);
}

struct post{
    ll f;
    ll p;
    string str;
};
bool cmp(post &a,post &b){
    a.p>b.p;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);
	//star{
	    ll i,N,M,n;
	    string str;
	    cin>>N>>M;
	    vll sf;
	    sf.clear();
	    fora(i,N){
	        cin>>n;
	        sf.pb(n);
	    }
	    ll f1=0,p1=0,str1;
	    vector<post> sp,fp;
	    sp.clear();
	    fp.clear();
	    for(i=0;i<M;i++){
	        fflush(stdin);
	        cin>>f1>>p1;
	        fflush(stdin);
	        cin>>str1;
	        post var;
	        var.f=f1;
	        var.p=p1;
	        var.str=str1;
	        if(find(sf.begin(),sf.end(),f1)!=sf.end()){
	            sp.pb(var);
	        }
	        else{
	            fp.pb(var);
	        }
	    }
	    sort(sp.begin(),sp.end(),cmp);
	    sort(fp.begin(),fp.end(),cmp);
	    for(i=0;i<sp.size();i++){
	        cout<<sp[i].str<<endl;
	    }
	    for(i=0;i<fp.size();i++){
	        cout<<fp[i].str<<endl;
	    }
    //cout<<endl;
	//}
return 0;
}
