#include <bits/stdc++.h>


#define endl '\n'


using namespace std;

typedef long long ll;


ll n,m;
vector<ll> vec;


bool can(ll days){
    ll cnt = 0;
    ll penalty = 0;
    ll go = 0;
    for (ll i = 0; i < vec.size(); ++i) {
        cnt+=max(0ll,(vec[i]-penalty));
        go++;
        if(go==days){
            go = 0;
            penalty++;
        }
    }
    return cnt>=m;
}


ll binarySearch(ll low, ll high){
    ll res = -1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(can(mid)){
            res = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>n>>m;
    ll num;
    for (ll i = 0; i < n; ++i) {
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end(),greater<ll>());
    cout<<binarySearch(1,1e9+2)<<endl;
}