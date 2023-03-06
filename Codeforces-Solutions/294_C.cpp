#include <bits/stdc++.h>


#define endl '\n'

using namespace std;

typedef long long ll;


const int MOD = 1000000007;

ll fact(ll num){
    ll res = 1;
    for (int i = 1; i <=num ; ++i) {
        res = (res*i)%MOD;
    }
    return res;
}


ll power(ll x , ll p){
    ll ret = 1;
    while(p){
        if(p&1) ret = ret*x %MOD;
        x = x*x % MOD;
        p/=2;
    }
    return ret;
}


ll modInverse(ll x){
    return power(x,MOD-2);
}

int main() {
    ll n,m;
    cin>>n>>m;
    ll up = n-m;
    ll go = fact(up);
    vector<ll> vec;
    ll num;
    for (int i = 0; i <m ; ++i) {
        cin>>num;
        vec.push_back(num);
    }

    sort(vec.begin(),vec.end());

    ll down = 1;
    down = (down*(fact(vec[0]-1)))%MOD;
    down= (down*(fact(n-vec[vec.size()-1])))%MOD;
    for (int i = 1; i < vec.size(); ++i) {
        down = (down*fact(vec[i]-vec[i-1]-1))%MOD;
    }

    ll ans = (go*modInverse(down))%MOD;

    ll hh = 1;
    for (int i = 1; i <vec.size() ; ++i) {
        if(vec[i]-vec[i-1]>1) hh = (hh*power(2,vec[i]-vec[i-1]-2))%MOD;
    }

    ans = (ans*hh)%MOD;

    cout<<ans<<endl;



}
