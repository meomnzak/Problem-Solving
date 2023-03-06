#include <bits/stdc++.h>


using namespace std;
int main(){
    int num,change;
    cin>>num>>change;
    int multi = 1;
    while( (num*multi)%10 != change &&  (num*multi)%10 != 0 ){
        multi+=1;
    }
    cout<<multi<<endl;
    return 0;
}