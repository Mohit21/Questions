#include<bits/stdc++.h>

using namespace std;

void insertSort(int A[],int n){
    for(int j=0;j<n;j++){
        int i,X;
        i=j-1;
        X=A[j];
        while(i>=0 && X<A[i]){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=X;
    }
}

int main(){
    //{ 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4}
int A[]={4, 10, 5, 3, 2, 6, 7, 8, 10, 9, 13, 12};
int N=sizeof(A)/sizeof(A[0]);
for(int i=0;i<N;i++){
    int B[i+1],n;
    B[0]=A[0];
    n=1;
    for(int j=1;j<=i;j++){
            B[j]=A[j];
    }
    n=(sizeof(B)/sizeof(B[0]));
    insertSort(B,n);
    /*for(int j=0;j<n;j++){
        cout<<"-->"<<B[j];
    }
    cout<<endl;
    */
    if(n%2==0){
            cout<<(B[(n/2)-1]+B[(n/2)])/2<<endl;
            }
    else if(n==1){
                cout<<B[0]<<endl;
            }
    else{
                cout<<B[(n/2)]<<endl;
            }
}

return 0;
}
