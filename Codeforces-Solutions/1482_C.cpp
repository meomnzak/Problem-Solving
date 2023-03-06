#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

const ll N = 2e3+7;

ll arr[N][N];


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        vector<pair<pair<ll,ll>,pair<ll,ll>>> vec(11,{{1e9,-1},{1e9,-1}});
        ll n;
        cin>>n;
        vector<ll> Ds = {0,n-1};
        for (ll i = 0; i < n; ++i) {
            string s;
            cin>>s;
            for (ll j = 0; j < s.size(); ++j) {
                arr[i][j] = s[j]-'0';
                vec[s[j]-'0'].first.first = min(vec[s[j]-'0'].first.first,i);
                vec[s[j]-'0'].first.second = max(vec[s[j]-'0'].first.second,i);
                vec[s[j]-'0'].second.first = min(vec[s[j]-'0'].second.first,j);
                vec[s[j]-'0'].second.second = max(vec[s[j]-'0'].second.second,j);
            }
        }
        vector<ll> sol(11,0);

        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                ll minRow = vec[arr[i][j]].first.first;
                ll maxRow = vec[arr[i][j]].first.second;
                for (ll k = 0; k < 2; ++k) {
                    sol[arr[i][j]] = max(sol[arr[i][j]],abs(i-minRow)*abs(Ds[k]-j));
                    sol[arr[i][j]] = max(sol[arr[i][j]],abs(i-maxRow)*abs(Ds[k]-j));
                }
                ll minCol = vec[arr[i][j]].second.first;
                ll maxCol = vec[arr[i][j]].second.second;
                for (ll k = 0; k < 2; ++k) {
                    sol[arr[i][j]] = max(sol[arr[i][j]],abs(j-minCol)*abs(Ds[k]-i));
                    sol[arr[i][j]] = max(sol[arr[i][j]],abs(j-maxCol)*abs(Ds[k]-i));
                }
            }
        }

        for (ll i = 0; i < 10; ++i) {
            cout<<sol[i]<<" ";
        }

        cout<<endl;

    }
}