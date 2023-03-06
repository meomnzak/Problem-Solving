#include <bits/stdc++.h>


#define endl '\n'


using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll sum = 0;
        int num;
        vector<int> vec;
        map<long double,int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            mp[num]++;
            vec.push_back(num);
            sum += num;
        }
        long double go = sum/(long double)n;
        int newN = n-2;
        long double newRes = newN*go;
        long double old = n*go;
        long double diff = old-newRes;
        ll res = 0;
        for (int i = 0; i < n; ++i) {
           int numm = vec[i];
           long double rem = diff-numm;
           mp[numm]--;
           res+=mp[rem];
        }

        cout<<res<<endl;

    }


}