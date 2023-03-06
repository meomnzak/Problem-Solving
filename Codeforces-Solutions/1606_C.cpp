#include <bits/stdc++.h>


#define endl '\n'

using namespace std;

typedef long long ll;

ll power(ll x, ll p){
    ll ret = 1;
    while(p){
        if(p&1) ret = ret*x;
        x = x*x;
        p/=2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
   ll ow = 10;
   ll begin = 1;
   vector<ll> vec;
    for (ll i = 0; i <=9; ++i) {
        vec.push_back(begin);
        begin*=ow;
    }
    ll t;
    cin>>t;
    while (t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> go;
        ll num;
        for (ll i = 0; i < n; ++i) {
            cin>>num;
            go.push_back(num);
        }
        ll prev = 0;
        k++;
        vector<ll> ans;
        for (ll i = 0; i < n; ++i) {
            ll can;
            if(i==n-1){
                can = -1;
            }else{
                can = (vec[go[i+1]]-vec[go[i]])/vec[go[i]];
            }

            ll rem = k-prev;
       //     cout<<rem<<endl;
            ll now = rem;
            if(now<=can || can == -1){
                ans.push_back(now);
                break;
            }else{
                ans.push_back(can);
                prev+=(can);
            }
        }
        ll best= 0;
        for (ll i = 0; i < ans.size(); ++i) {
            best+=(ans[i]*vec[go[i]]);
        }
        cout<<best<<endl;
    }

}