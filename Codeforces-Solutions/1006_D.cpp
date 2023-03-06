#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    string sA;
    string sB;
    cin>>sA>>sB;
    int count= 0;
    if(n%2==1){
        if(sA[n/2]!=sB[n/2]){
            count++;
        }
    }
    for(int i = 0 ; i<n/2 ; i++){
        if(sB[i]==sB[n-i-1]){
            if(sA[i]!=sA[n-i-1]){
                count++;
            }
        }else{
            if(!(sB[i] == sA[i] || sB[i]== sA[n-i-1])){
                count++;
            }
            if(!(sB[n-i-1] == sA[i] || sB[n-i-1]== sA[n-i-1])){
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}