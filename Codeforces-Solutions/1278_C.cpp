#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num;
        vector<int> vec1;
        vector<int> vec2;
        int balance = 0;
        for (int i = 0; i < n; ++i) {
            cin>>num;
            if(num==1){
                balance++;
            }else{
                balance--;
            }
            vec1.push_back(num);
        }
        reverse(vec1.begin(),vec1.end());
        for (int i = 0; i < n; ++i) {
            cin>>num;
            if(num==1){
                balance++;
            }else{
                balance--;
            }
            vec2.push_back(num);
        }
        if(balance==0){
            cout<<0<<endl;
            continue;
        }
        int ans = 1e9+7;
        map<int,int> mp;
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            if(vec1[i]==1){
                temp--;
            }else{
                temp++;
            }
            if((temp+balance)==0){
                ans = min(ans,(i+1));
            }
            if(mp.find(temp)==mp.end()){
                mp[temp] = (i+1);
            }
        }

        int another = 0;
        for (int i = 0; i < n; ++i) {
            if(vec2[i]==1){
                another--;
            }else{
                another++;
            }
            if((another+balance)==0){
                ans = min(ans,(i+1));
            }
            int val = balance+another;
            val*=-1;
            if(mp.find(val)!=mp.end()){
                ans = min(ans,(mp[val]+(i+1)));
            }
        }

        cout<<ans<<endl;

    }


}