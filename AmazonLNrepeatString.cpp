#include<bits/stdc++.h>
using namespace std;

void lNRS(string str){
int N=str.size(),curlen=0,prev,maxlen=0;
int v[26];
for(int i=0;i<26;i++){
    v[i]=-1;
}
v[str[0]-'A']=0;
for(int i=1;i<N;i++){
    prev=v[str[i]-'A'];
    if(prev==-1 || i-curlen>prev){
        ++curlen;
    }
    else{
        if(maxlen<curlen){
            maxlen=curlen;
            curlen=i-prev;
        }
    }
    v[str[i]-'A']=i;
}
cout<<maxlen<<endl;
}

int main(){
string str;
//ABCDEADEEFGH
cin>>str;
lNRS(str);
return 0;
}
