#include <bits/stdc++.h>


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int val = ceil(double(k)/double(n-1));
        val--;
        cout<<k+val<<endl;
    }
    return 0;
}