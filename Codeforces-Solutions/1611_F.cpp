#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;

    while(t--){
       ll n,beg;
       cin>>n>>beg;
       vector<ll> vec;
       ll num;
        for (ll i = 0; i < n; ++i) {
            cin>>num;
            vec.push_back(num);
        }
        ll summ = beg;
        ll maxLength = 0;
        pair<ll,ll> res = {-1,-1};
        ll l = 0;
        ll r = 0;
        while(l<n){
            while(r<n && summ+vec[r]>=0){
                summ+=vec[r];
                if((r-l)+1>maxLength){
                    maxLength = (r-l)+1;
                    res = {l+1,r+1};
                }
                r++;
            }
            summ-=vec[l];
            l++;
        }
        if(res.first==-1){
            cout<<-1<<endl;
        }else{
            cout<<res.first<<" "<<res.second<<endl;
        }


    }
    return 0;

}
