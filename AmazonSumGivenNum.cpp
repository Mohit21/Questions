#include<bits/stdc++.h>
using namespace std;
bool sum(int A[],int N,int x){
    int l=0,r=N-1;
    while(l<r){
        if(A[l]+A[r]<x){
            l++;
        }
        else if(A[l]+A[r]>x){
            r--;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
int A[]={4,5,6,7,8,9,11};
int N=sizeof(A)/sizeof(A[0]),x;
x=15;           // 44 45 16
if(sum(A,N,x)){
    cout<<"Yes";
}
else{
    cout<<"No";
}
return 0;
}
