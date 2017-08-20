#include<bits/stdc++.h>
using namespace std;
/*
int median(int A1[],int A2[],int N){
int i=0,j=0,m1=0,m2=0;
for(int k=0;k<=N;k++){
        if(i==N){
            m1=m2;
            m2=A2[0];
            break;
        }
        if(j==N){
            m1=m2;
            m2=A1[0];
            break;
        }
        if(A1[i]>A2[j]){
            m1=m2;
            m2=A2[j++];
        }
        else{
            m1=m2;
            m2=A1[i++];
        }
    }
return ((m1+m2)/2);
}
*/
int med(int A[],int N){
    if(N%2==0){
        return (A[N/2]+A[N/2-1])/2;
    }
    else{
        return (A[N/2]);
    }
}

int median(int A1[],int A2[],int N){
    if(N==0){
        return -1;
    }
    if(N==1){
        return (max(A1[0],A2[0]))/2;
    }
    if(N==2){
        return (max(A1[0],A2[0])+min(A1[1],A2[1]))/2;
    }
    int m1,m2;
    m1-med(A1,N);
    m2=med(A2,N);

    if(m1==m2){
        return m1;
    }
    if(m1<m2){
        if(N%2==0){
            return median(A1+N/2-1,A2,N-N/2+1);
        }
        return median(A1+N/2,A2,N-N/2);
    }
    else{           //mi>m2
        if(N%2==0){
            return median(A2+N/2-1,A1,N-N/2+1);
        }
        return median(A2+N/2,A1,N-N/2);
    }
}

int main(){
int A1[]={1, 12, 15, 26, 38},A2[]={2, 13, 17, 30, 45};
int N=sizeof(A1)/sizeof(A1[0]);
int med=median(A1,A2,N);
if(med==-1){
    cout<<"Not Found";
}
else{
    cout<<med<<endl;
}
return 0;
}
