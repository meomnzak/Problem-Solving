#include <bits/stdc++.h>


#define endl '\n'



using namespace std;

typedef long long ll;




int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> vec;
        ll num;
        for (ll i = 0; i < n; ++i) {
            cin>>num;
            vec.push_back(num);
        }
        sort(vec.begin(),vec.end(),greater<ll>());
        ll mini = vec.back();
        while(mini==vec.back()){
            vec.pop_back();
        }
        if(vec.size()==0){
            cout<<-1<<endl;
            continue;
        }
        for (ll i = 0; i < vec.size(); ++i) {
            vec[i] = vec[i]-mini;
        }
        ll gg = vec[0];
        for (ll i = 0; i < vec.size(); ++i) {
            gg = __gcd(gg,vec[i]);
        }


        cout<<gg<<endl;
    }
}