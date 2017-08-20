#include<iostream>
using namespace std;

int LSA(int A[],int N,int sum){
int tsum=0,maxLen=0;
for(int i=0;i<N;i++){
    tsum+=A[i];
}
if(tsum==sum){
    maxLen=N;
    return maxLen;
}
else{
    tsum=0;
    for(int i=0;i<N;i++){
        tsum=A[i];
        for(int j=i+1;j<N;j++){
            if(tsum==sum){
                if(maxLen<(j-i)){
                    maxLen=(j-i);
                }
            }
            tsum+=A[j];
        }
    }
if(maxLen==0){
    return -1;
}
else{
    return maxLen;
}
}
}

int main(){
int N,sum;
cin>>N;
int A[N];
for(int i=0;i<N;i++){
    cin>>A[i];
}
cin>>sum;
cout<<LSA(A,N,sum);
return 0;
}
