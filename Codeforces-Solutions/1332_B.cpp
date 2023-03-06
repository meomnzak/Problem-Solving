#include <bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i = 0 ; i<n ; i++){
            cin>>vec[i];
        }
        vector<int> sol(n,0);
        int k = 1;
        int temp = n;
        int val = 2;
        while(temp){
            bool flag = false;
            for(int i = 0 ; i<n ; i++){
                if(sol[i]==0){
                    if(vec[i]%val==0){
                        sol[i] = k;
                        temp--;
                        flag= true;
                    }
                }
            }
            if(flag){
                k++;
            }
            val++;
        }
        
        cout<<--k<<endl;
        for(int i = 0 ; i<n ; i++){
            cout<<sol[i];
            if(i!=n-1){
                cout<<" ";
            }
        }
        cout<<endl;
        
    }
    return 0;
}