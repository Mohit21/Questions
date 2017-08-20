#include<bits/stdc++.h>

using namespace std;

bool all9(int A[],int N){
    bool flag=true;
    for(int i=0;i<N;i++){
        if(A[i]!=9){
            flag=false;
            break;
        }
    }
    return flag;
}

void getNextGreat(int A[],int N){
    int start=0,end=N;
    if(all9(A,N)){
      /*If all digits in N are 9
    then the next greater is n+1 digits with first and last number as 1 and all 0's
    */
    /*
    A=(int *)calloc((N+1),sizeof(int));
    for(int i=0;i<=N;i++){
            if(i==0){
                A[i]=1;
            }
            else if(i==N){
                A[i]=1;
            }
            else{
                A[i]=0;
            }
        }
    for(int i=0;i<=N;i++)cout<<A[i];
        cout<<endl;
    */
        for(int i=0;i<=N;i++){
            if(i==0 || i==N){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
    }
    else{
    int mid=(end-start)/2;
    if(A[mid]+1>9){
            int car,car1;
            A[mid]=(A[mid]+1)%10;
            car=1;
            for(int i=mid-1;i>=0;i--){
                car1=A[i]+car>9?1:0;
                A[i]=(A[i]+car)%10;
                car=car1;
            }
            for(int i=mid+1;i<end;i++){
                    A[i]=A[N-i-1];
            }
    }
    else{
            A[mid]=A[mid]+1;
            for(int i=mid+1;i<end;i++){
                    A[i]=A[N-i-1];
            }
        }
        for(int i=0;i<N;i++){
                cout<<A[i];
        }
    }

}


int main(){
int A[]={1,3,3,9,2,3,1};  //{1,2,1,2,1} {1 ,2 ,9 ,2 ,1} {9,9,9,9,9,9,9} {1,9,9,9,9,1} {1,3,3,9,2,3,1}
int N=sizeof(A)/sizeof(A[0]);
getNextGreat(A,N);
return 0;
}
