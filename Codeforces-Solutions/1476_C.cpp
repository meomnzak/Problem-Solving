#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

const ll N = 1e5+6;

ll n;

ll possible[N];
ll length[N];

ll first[N];
ll second[N];

ll meme[N][3];


ll solve(ll idx, bool begin){
    if(idx==n){
        return 0;
    }
    ll &ret = meme[idx][begin];
    if(~ret) return ret;
    ret = 0;
    ll have = 0;
    if(begin==1){
        ret+=second[idx]-first[idx]+1;
    }else if(possible[idx]==0 || idx==n-1) {
        ret+=length[idx];
    }else{
        have+=2;
        if(first[idx]!=1){
            have+=first[idx]-1;
        }
        if(second[idx]!=length[idx]){
            have+=length[idx]-second[idx];
        }
    }
    if( idx!=n-1 && (possible[idx]==1||begin==1)){
        ll go = 0;
        if(begin!=1){
            go+=length[idx];
        }
        ret+=max(solve(idx+1,0)+have,go);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        memset(meme,-1,sizeof(meme));
        cin>>n;
        for (ll i = 0; i < n; ++i) {
            cin>>length[i];
        }
        ll gar;
        for (ll i = 0; i <n ; ++i) {
            if(i==0){
                cin>>gar;
                continue;
            }
            cin>>first[i-1];
        }

        for (ll i = 0; i <n ; ++i) {
            if(i==0){
                cin>>gar;
                continue;
            }
            cin>>second[i-1];
        }

        first[n-1] = 1;
        second[n-1] = length[n-1];

        for (ll i = 0; i < n; ++i) {
            if(first[i]>second[i]) swap(first[i],second[i]);
            if(first[i]!=second[i]){
                possible[i] = 1;
            }else{
                possible[i] = 0;
            }
        }

        ll maxx = 0;

        for (ll i = 0; i < n; ++i) {
            maxx = max({maxx,solve(i,1)});
            //  if(maxx==10){cout<<i<<endl;}
        }
        //
        cout<<maxx<<endl;

    }
//


}