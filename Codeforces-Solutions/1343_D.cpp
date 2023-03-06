#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;





const int N = 1<<20;

struct node {
    ll sum, lazy;

    void addLazy(ll v, int ss, int se) {
        sum += v * (se - ss + 1);
        lazy += v;
    }
};

node seg[N];

void pushDown(int si, int ss, int se) {
    node &cur = seg[si];
    if (cur.lazy == 0 || ss == se) return;
    int md = ss + (se - ss) / 2, rt = 2 * si + 1, lf = rt++;
    seg[lf].addLazy(cur.lazy, ss, md);
    seg[rt].addLazy(cur.lazy, md + 1, se);
    cur.lazy = 0;
}

int n;

void build(int si = 0, int ss = 0, int se = n - 1) {
    if (ss == se) {
        seg[si].sum = 0; //or a[ss]
        seg[si].lazy = 0;
        return;
    }
    int md = ss + (se - ss) / 2, rt = 2 * si + 1, lf = rt++;
    build(lf, ss, md);
    build(rt, md + 1, se);
    seg[si].sum = seg[lf].sum + seg[rt].sum;
    seg[si].lazy = 0;
}

void addRange(int qs, int qe, int qv, int si = 0, int ss = 0, int se = n - 1) {
    if (qs > se || qe < ss) return;
    if (ss >= qs && se <= qe) {
        seg[si].addLazy(qv, ss, se);
        return;
    }

    pushDown(si, ss, se);
    int md = ss + (se - ss) / 2, rt = 2 * si + 1, lf = rt++;
    addRange(qs, qe, qv, lf, ss, md);
    addRange(qs, qe, qv, rt, md + 1, se);
    seg[si].sum = seg[lf].sum + seg[rt].sum;
    //I know that seg[si].lazy is 0
}

ll queryRange(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
    if (qs > se || qe < ss) return 0;
    if (ss >= qs && se <= qe) {
        return seg[si].sum;
    }

    pushDown(si, ss, se);
    int md = ss + (se - ss) / 2, rt = 2 * si + 1, lf = rt++;

    return queryRange(qs, qe, lf, ss, md) +
           queryRange(qs, qe, rt, md + 1, se);
}




int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){

        int sz;
        cin>>sz;
        int k;
        cin>>k;
        n = k*2;
        n++;
        build();
        vector<int> vec;
        int num;
        for (int i = 0; i < sz; ++i) {
            cin>>num;
            vec.push_back(num);
        }
        unordered_map<int,int> mp;
        for(int i = 0 ,j=sz-1 ; i<sz/2 ; i++,j--){
            int first= vec[i];
            int second = vec[j];
            mp[first+second]++;
            addRange(min(first,second)+1,max(first,second)+k,1);
        }
        int ans = 1e9;
        for (int i = 0; i < n; ++i) {
            int now = queryRange(i,i);
            ans = min(ans,((now-mp[i])+(2*((sz/2)-now))));
        }
        cout<<ans<<endl;
    }
}