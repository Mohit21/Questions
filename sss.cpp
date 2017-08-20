#include<bits/stdc++.h>

using namespace std;

int main(){
float t,x,y,z,x1,y1,z1,sx,sy,sz,sx1,sy1,sz1;
cin>>t;
cin>>x>>y>>z;
cin>>sx>>sy>>sz;
cin>>x1>>y1>>z1;
cin>>sx1>>sy1>>sz1;
float dis=0,mind=0;
float xd,yd,zd;
xd=abs(x1-x);
yd=abs(y1-y);
zd=abs(z1-z);
dis=sqrt((xd*xd)+(yd*yd)+(zd*zd));
mind=dis;
for(int i=0;i<t;i++){
    x+=sx;
    y+=sy;
    z+=sz;

    x1+=sx1;
    y1+=sy1;
    z1+=sz1;

    xd=abs(x1-x);
    yd=abs(y1-y);
    zd=abs(z1-z);

    dis=sqrt((xd*xd)+(yd*yd)+(zd*zd));
    if(mind>dis){mind=dis;}
}
cout<<endl<<"-->"<<mind<<endl;
return 0;
}
