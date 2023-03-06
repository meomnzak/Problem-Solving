#include <iostream>


using namespace std;
int main(){
    int t;
    cin>>t;
    int one,two;
    while(t--){
        cin>>one>>two;
        if(one%two==0){
            cout<<0<<endl;
        }else{
            int temp = one/two;
            temp++;
            int remain = temp*two;
            int sol = (abs(remain-one));
            cout<<sol<<endl;
        }
    }
    return 0;
}