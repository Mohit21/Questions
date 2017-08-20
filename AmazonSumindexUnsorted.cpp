#include<iostream>
#define size 1000
using namespace std;
// found and 1 if found else 0
int maxSum(int A[],int N,int x){
int hashmap[size]={0},x1;
for(int i=0;i<N;i++){
        x1=x-A[i];
        if(x1>=0 && hashmap[x1]==1){
            cout<<"found";
            return 1;
        }
        hashmap[A[i]]=1;
}
return 0;
}

int main(){
int A[]={2,5,3,7,8,6,11},x=9;
//x=55,14,25e
int N=sizeof(A)/sizeof(A[0]);
cout<<maxSum(A,N,x);
return 0;
}
