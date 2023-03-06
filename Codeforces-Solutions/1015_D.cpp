#include <bits/stdc++.h>


using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long dist;
    cin>>dist;
    long long curr = 1;
    bool flag = false;
    if(k>dist || k*(n-1)<dist){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        while(k){
            long long move = min(n-1,dist-(k-1));
            if(!flag){
                curr+=move;
            }else{
                curr-=move;
            }
            cout<<curr;
            if(k!=0){
                cout<<" ";
            }
            flag = !flag;
            dist-=move;
            k--;
        }
    }
    cout<<endl;
    
    return 0;
}