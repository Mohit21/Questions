#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<climits>
#include<fstream>
using namespace std;
#define ll long long int

inline ll max(ll a,ll b){return (a>b?a:b);}

inline ll min(ll a,ll b){return (a<b?a:b);}

inline ll findL(bool visit[],ll N,ll stall){
    ll countl=0;
    for(ll i=stall-1;i>=0;i--){
        if(!visit[i]){countl++;}
        else{break;}
    }
    return countl;
}

inline ll findR(bool visit[],ll N,ll stall){
    ll countr=0;
    for(ll i=stall+1;i<N;i++){
        if(!visit[i]){countr++;}
        else{break;}
    }
    return countr;
}

int main(){
    ll T=100,T1=0;
    ofstream outfile;
    outfile.open("smallOutput.txt");
    ifstream infile;
    infile.open("smallInput.txt");
    while(!infile.eof()){
        ll N,K,minLR=0,maxLR=0,L,R;
        //cin>>N>>K;
        infile>>N>>K;
        if(N==K){maxLR=0;minLR=0;}
        else if(K==1){
                if(N%2==0){maxLR=N/2;minLR=(N/2)-1;}
                else{maxLR=(N/2)+1;minLR=N/2;}
        }
        else{
                bool visit[N];
                for(ll i=0;i<N;i++){visit[i]=false;}
                ll pos,j=0;
                while(K--){
                    map<ll,pair<ll,ll> > mp;
                    vector<ll> v,w,minv;
                    v.clear();
                    w.clear();
                    minv.clear();
                    vector<pair<ll,ll> > maxv;
                    maxv.clear();
                    if(j==0){
                       if(N%2==0){
                            maxLR=N/2;
                            minLR=(N/2)-1;
                            visit[N/2-1]=true;
                       }
                        else{
                            maxLR=(N/2)+1;
                            minLR=N/2;
                            visit[(N/2)+1-1]=true;
                       }
                    }
                    else{
                        ll min1=INT_MAX,minprev,maxm=INT_MIN;
                        for(ll i=0;i<N;i++){
                            if(!visit[i]){
                                L=findL(visit,N,i);
                                R=findR(visit,N,i);
                                pair<ll,ll> p;
                                p=make_pair(L,R);
                                mp[i]=p;

                                min1=min(L,R);
                                minv.push_back(min1);
                                if(maxm<min1){maxm=min1;}
                            }
                            else{
                                minv.push_back(INT_MAX);
                            }
                        }
                        for(ll i=0;i<minv.size();i++){
                            if(maxm==minv[i]){
                                v.push_back(i);
                            }
                        }
                        if(v.size()==1){
                            pos=v[0];
                            maxLR=max(mp[v[0]].first,mp[v[0]].second);
                            minLR=min(mp[v[0]].first,mp[v[0]].second);
                        }
                        else{
                            ll max1=INT_MIN;
                            maxm=INT_MIN;
                            for(ll i=0;i<v.size();i++){
                                L=mp[v[i]].first;
                                R=mp[v[i]].second;
                                max1=max(L,R);
                                maxv.push_back(make_pair(max1,v[i]));
                                if(maxm<max1){maxm=max1;}
                            }
                            for(ll i=0;i<maxv.size();i++){
                            if(maxm==(maxv[i].first)){
                                w.push_back(maxv[i].second);
                                }
                            }
                            pos=w[0];
                            maxLR=max(mp[w[0]].first,mp[w[0]].second);
                            minLR=min(mp[w[0]].first,mp[w[0]].second);
                        }
                        visit[pos]=true;
                    }
                    ++j;
                }
        }
        outfile<<"Case #"<<++T1<<": "<<maxLR<<" "<<minLR<<endl;
        cout<<T1<<endl;
    }
    outfile.close();
    infile.close();
return 0;
}
