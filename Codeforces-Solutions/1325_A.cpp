#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    int num;
    while(n--){
        cin>>num;
        if(num==2){
            cout<<1<<" "<<1<<endl;
        }else{
            cout<<num-1<<" "<<1<<endl;
        }
    }
    return 0;
}