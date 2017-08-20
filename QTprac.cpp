#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T--){
        long long int n,c=0;
        cin>>n;
        long long int a[n+1];
        long long int B[501]={0};
        a[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            B[a[i]]++;
        }
        bool flg=false;
        for(int i=1;i<=n;i++)
        {
            if(B[i]==0){
                flg=true;
                break;
            }
            if(a[i]==i){
                c++;
            }
        }
        if(flg==false && c!=n){
            cout<<"yes";
        }
        else{
            cout<<"no";
        }
        cout<<endl;
    }
    return 0;
}
