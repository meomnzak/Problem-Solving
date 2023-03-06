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
    vector<ll> vec;
    for (ll i = 0; i <=61; ++i) {
        vec.push_back(power(2ll,i));
    }
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans = lower_bound(vec.begin(),vec.end(),n)-vec.begin()-1;
        ll maxSteps = upper_bound(vec.begin(),vec.end(),k)-vec.begin()-1;
        if(ans<=maxSteps){
            cout<<ans+1<<endl;
            continue;
        }
        ll tot = (vec[maxSteps+1]-1);
        n-=tot;
        n--;
        ll go = ceil(n/(double)k);
        cout<<go+(maxSteps+1)<<endl;
    }
}