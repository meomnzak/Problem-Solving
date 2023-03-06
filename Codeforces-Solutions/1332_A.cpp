#include <iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    int left,right,down,up;
    int x,y;
    int x1,y1,x2,y2;
    while(t--){
        cin>>left>>right>>down>>up;
        int valX = right-left;
        int valY = up-down;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        int tempX= x+ valX;
        int tempY= y+ valY;
        if(tempX>=x1 && tempX<=x2 && tempY>=y1 && tempY<=y2){
            if( ((x==x1 && x==x2) && left>0) || ((y==y1 && y==y2) && up>0)){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}