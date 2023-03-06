#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    int num;
    for(int i = 0 ; i<n ; i++){
        cin>>num;
        if(num%2==0){
            cout<<num-1;
        }else{
            cout<<num;
        }
        if(i!=n-1){
            cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}