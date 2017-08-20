#include<iostream>
#include<cmath>
#include<algorithm>
//#include<bits/stdc++.h>

using namespace std;

/*
Testcase:
1. (0, 0) and (5,5), (2,2) and (7,7). Answer is 9.
2. (4,4) and (5,6), (2,3) and (7,7) = 2
3. (0,5) and (3,15), (-2,7) and (2,10) = 6
4. (-2,7) and (2,10), (2,7) and (4,15) = 0

Testcases passed-1,2,4
*/

int main(){
    int x1,x2,x3,x4,y1,y2,y3,y4,x11,x22,x33,x44,y11,y22,y33,y44,s1,s2;
    cin>>x1>>y1;
    cin>>x3>>y3;
    cin>>x11>>y11;
    cin>>x33>>y33;
    //Remaimning 2 cooridnates first rectangle1
    x2=x3;
    y2=x1;
    x4=x1;
    y4=y3;
    //Remaimning 2 cooridnates first rectangle2
    x22=x33;
    y22=x11;
    x44=x11;
    y44=y33;
    //if both the rectangles overlap
    if((x1==x11 && y1==y11) &&(x3==x33 && y3==y33) ){
        s1=sqrt(((x4-x3)*(x4-x3))+((y4-y3)*(y4-y3)));
        s2=sqrt(((x2-x1)*(x2-x1))+((y1-y2)*(y1-y2)));
        cout<<s1*s2;
    }
    else if(x33>=x4 && x11>=x2){
        //rectangle1 is left of the other rectangle2
        cout<<-1;
    }
    else if(y1>=y44 && y2>=y33){
        //rectangle1 is down the other rectangle2
        cout<<-1;
        }
    else if(x11>=x2 && x44>=x3){
        //rectangle1 is right of the other rectangle2
        cout<<-1;
    }
    else if(y4<=y11 && y3<=y22){
        //rectangle1 is above of the other rectangle2
        cout<<-1;
    }
    else{
        /*Formula deduced from:
        http://math.stackexchange.com/questions/99565/simplest-way-to-calculate-the-intersect-area-of-two-rectangles
        */
        s1 =max(0, abs(min(x2,x22) - max(x1,x11)));
        s2 =max(0, abs(max(y2,y22) - min(y3,y33)));
        cout<<s1*s2;
    }
    //system("pause");
    return 0;
}
