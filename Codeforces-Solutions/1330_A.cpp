#include <bits/stdc++.h>


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        map<int,int> m;
        int n;
        int x;
        cin>>n>>x;
        int num;
        int largest = 0;
        for(int i = 0 ; i<n ; i++){
            cin>>num;
            m[num] = 1;
        }
        for(int i =  1 ; i<=500 ; i++){
            if(m[i]==0){
                m[i] = 1;
                x--;
            }
            if(x==0){
                break;
            }
        }
        int count = 0;
        for(int i = 1 ; i<=500 ; i++){
            if(m[i]==0){
                break;
            }else{
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}