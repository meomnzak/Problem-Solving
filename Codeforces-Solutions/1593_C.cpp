#include <bits/stdc++.h>


#define endl '\n'



using namespace std;

typedef long long ll;




int main() {
    ll t;
    cin>>t;
    while(t--){
       ll n,k;
       cin>>n>>k;
       priority_queue<ll> pq;
       ll num;
        for (ll i = 0; i < k; ++i) {
            cin>>num;
            pq.push(num);
        }
        ll moved = 0;
        ll cat =0;
        ll cnt = 0;
        while(pq.size()>0){
            ll go = pq.top();
            pq.pop();
            cat=moved;
            if(cat>=go){
                break;
            }
            moved+=(n-go);
            cnt++;
        }
        cout<<cnt<<endl;
    }
}