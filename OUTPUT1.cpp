#include<iostream>
#include<fstream>
using namespace std;
#define ll long long int
int main(){
    ofstream outfile;
    outfile.open("large1.txt");
    int N=1000,N1=50,N2=20;
    int K1=20,K=500,K2=2,j=0;
    for(ll i=0;i<100;i++){
        if(j%3==0){
            outfile<<N<<" "<<K<<endl;
        }
        else if(j%3==1){
            outfile<<N1<<" "<<K1<<endl;
        }
        else{
            outfile<<N2<<" "<<K2<<endl;
        }
        j++;
    }
    outfile.close();
return 0;
}
