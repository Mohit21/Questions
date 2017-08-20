#include<iostream>

using namespace std;
int maxSum(int A[],int N){
int maxsum=0,sum;
for(int i=0;i<N;i++){
        sum=A[i];
        for(int j=i+2;j<=N;j+=2){
            sum+=A[j];
            if(maxsum<sum){
                maxsum=sum;
            }
            else{
                sum-=A[j];
            }
    }

}
return (maxsum>0?maxsum:0);
}

int main(){
int A[]={1,5,3,7,9,11,55};
int N=sizeof(A)/sizeof(A[0]);
cout<<maxSum(A,N);
return 0;
}
