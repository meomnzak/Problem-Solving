#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;


const int MOD = 1e9+7;

ll nCrModp(ll n, ll r)
{
    if (r > n - r)
        r = n - r;

    ll C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % MOD;
    }
    return C[r];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec;
        int num;
        map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            cin>>num;
            mp[num]++;
            vec.push_back(num);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        map<int,int> cnt;
        for (int i = 0; i < k; ++i) {
            cnt[vec[i]]++;
        }
        ll ans = 1;
        for(auto it = cnt.begin() ; it!=cnt.end() ; it++){
            ans = (((ans)%MOD) * (nCrModp(mp[it->first],it->second)%MOD))%MOD;
        }
        cout<<ans<<endl;
    }


}