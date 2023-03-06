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
        deque<ll> vec;
        ll num;
        for (ll i = 0; i < n; ++i) {
            cin>>num;
            vec.push_back(num);
        }
        if(vec.size()==1){
            cout<<vec[0]<<endl;
        }else{
            sort(vec.begin(),vec.end());
            if(vec[0]<0){
                ll val = vec.front();
                vec.pop_front();
                for (ll i = 0; i < vec.size(); ++i) {
                    vec[i]+=abs(val);
                }
            }
            ll maxi = vec.front();
            for (ll i = 0; i < vec.size()-1; ++i) {
                maxi = max(maxi,vec[i+1]-vec[i]);
            }
            cout<<maxi<<endl;
        }

    }

}