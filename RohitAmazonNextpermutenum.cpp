#include<bits/stdc++.h>

using namespace std;

int main(){
int n,b,dis1,dis2,temp;
//514321->541123   35271->35721   2134->2143   223114->223114
cin>>n;
vector<int> v;
vector<int>:: iterator it,it1;
vector<int>:: reverse_iterator rit;
while(n!=0){
    b=n%10;
    v.push_back(b);
    n/=10;
}
it1=v.begin();
for(it=v.begin();it!=v.end();it++){
    ++it1;
    if(*(it1)-*(it)<0){
        dis1=it1-v.begin();
        dis2=it-v.begin();
        break;
    }
}
//cout<<endl<<dis1<<" "<<dis2<<endl;
temp=v[dis1];
v[dis1]=v[dis1-1];
v[dis1-1]=temp;
dis2=v.size()-dis2;
sort(v.rbegin()+dis2,v.rend());
n=0;
for(rit=v.rbegin();rit!=v.rend();rit++){
    n=(n*10)+(*rit);
}
cout<<n;
return 0;
}
