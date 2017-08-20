#include<iostream>
using namespace std;
int lSubSum(int A[],int N,int sum){
int tsum=0,maxlen=0;
for(int i=0;i<N;i++){
    tsum+=A[i];
}
if(tsum==sum){
    maxlen=N;
    return maxlen;
}
else{
    tsum=0;
    for(int i=0;i<N;i++){
        tsum=A[i];
        for(int j=i+1;j<N;j++){
            if(tsum==sum){
                if(maxlen<(j-i)){
                    maxlen=j-i;
                }
            }
        tsum+=A[j];
        }
    }
if(maxlen==0){
    return -1;
}
else{
    return maxlen;
}
}
}

int main(){
int N;
cin>>N;
int A[N];
for(int i=0;i<N;i++){
    cin>>A[i];
}
int sum=0;
cin>>sum;
cout<<lSubSum(A,N,sum);
return 0;
}
