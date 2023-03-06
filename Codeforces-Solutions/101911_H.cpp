#include <bits/stdc++.h>


#define endl '\n'



using namespace std;

typedef long long ll;




int main() {
    int t;
    cin>>t;
    while(t--){
        int one,two,three;
        cin>>one>>two>>three;
        vector<int> vec = {one,two,three};
        sort(vec.begin(),vec.end(),greater<int>());
        int maxi = vec[0];
        bool flag = false;
        if(vec[1]==maxi){
            flag= true;
        }
        if(one==maxi){
            if(!flag){
                cout<<0<<" ";
            }else{
                cout<<1<<" ";
            }
        }else{
            cout<<maxi-one+1<<" ";
        }
        if(two==maxi){
            if(!flag){
                cout<<0<<" ";
            }else{
                cout<<1<<" ";
            }
        }else{
            cout<<maxi-two+1<<" ";
        }
        if(three==maxi){
            if(!flag){
                cout<<0<<" ";
            }else{
                cout<<1<<" ";
            }
        }else{
            cout<<maxi-three+1<<" ";
        }
        cout<<endl;
    }
}