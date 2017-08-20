#include<bits/stdc++.h>

using namespace std;

int main(){
    long long N,X,S,diff=0,min_Size=0,i,ans;
    vector<long long> v;
    v.clear();
    vector<long long>::iterator it;
    long long *p;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>X;
        v.push_back(X);
    }
    cin>>S;
    long long max_Size_Box=*(max_element(v.begin(),v.end()));
    if(max_Size_Box<S){
        cout<<"-1";
    }
    else{
            i=0;
            for(it=v.begin();it!=v.end();it++){
                if(S<=*it){
                    diff=*it-S;
                    if(i==0){
                        min_Size=diff;
                        ans=*it;
                        i++;
                    }
                    else if(min_Size>diff){
                        min_Size=diff;
                        ans=*it;
                    }
                }
            }
        cout<<ans;
    }
    return 0;
}
