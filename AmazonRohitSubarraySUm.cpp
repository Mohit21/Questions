#include<iostream>
using namespace std;

int lSum(int A[],int N,int sum){
int tSum=0,maxlen=0;
    for(int i=0;i<N;i++){
        tSum+=A[i];
    }
    if(sum==tSum){
        maxlen=N;
        return maxlen;
    }
    else{
            tSum=0;
            for(int i=0;i<N;i++){
                    tSum=A[i];
                for(int j=i+1;j<N;j++){
                if(tSum==sum){
                        if((maxlen)<(j-i)){
                            maxlen=(j-i);
                        }
                    }
                tSum+=A[j];
                }
            }
        if(maxlen==0){
            return -1;
        }
        else{
            return (maxlen);
        }
    }
}

int main(){

/*int A[]={7,3,4,1,10};
int N=sizeof(A)/sizeof(A[0]);
int sum=2;
*/
int N,sum;
cin>>N;
int A[N];
for(int i=0;i<N;i++){
    cin>>A[i];
}
cin>>sum;
cout<<lSum(A,N,sum)<<endl;
return 0;
}
