#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int LIS(int A[],int N){
    int dp[N],ans=0;
    dp[0]=1;
    for(int i=1;i<N;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
return ans;
}


int LISS(int A[],int N){
    int dp[N],ans=A[0];
    dp[0]=A[0];
    for(int i=1;i<N;i++){
        dp[i]=A[i];
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                dp[i]=max(dp[i],dp[j]+A[i]);
            }
        }
        ans=max(ans,dp[i]);
    }
return ans;
}

int main(){
    int A[]={10, 22, 9, 33, 21, 50, 41, 60};
    int N=sizeof(A)/sizeof(A[0]);
    cout<<"Longest Increasing Subsequence: "<<LIS(A,N)<<endl<<endl;
    cout<<"Longest Increasing Sum Subsequence: "<<LISS(A,N)<<endl;
return 0;
}
