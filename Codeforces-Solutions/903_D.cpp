/*
 * بسم الله الرحمن الرحيم
 * Author : Belal Moawad
 */
#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
#define ll long double
#define f first
#define s second
typedef vector<ll> vi;
typedef pair<ll , ll> pii;
const long long N = (1 << 20) , OO = 1e18 , mod = 1e9 + 7;
/******************* 3la allah **********************/
ll n , v[N] , Copy[N] , all[N];
int allc;

struct node {
    ll sum , freq;
}tree[N << 1];

void init(int ni = 0, ll ns = 0, ll ne = allc - 1) {
    if(ns == ne) {
        tree[ni].sum = tree[ni].freq = 0;
        return;
    }
    tree[ni].sum = tree[ni].freq = 0;
    int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
    init(lf, ns, mid);
    init(rt, mid + 1, ne);
}

pii query(ll qs, ll qe, int ni = 0, ll ns = 0, ll ne = allc - 1) { // sum , how many
    if (ne < qs or ns > qe) return {0 , 0};
    if (ns >= qs and ne <= qe) return {tree[ni].sum , tree[ni].freq};
    int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
    pii LF = query(qs, qe, lf, ns, mid);
    pii RT = query(qs, qe, rt, mid + 1, ne);
    return {LF.f + RT.f , LF.s + RT.s};
}

void update(ll pos, ll val, int ni = 0, ll ns = 0, ll ne = allc - 1) {
    if (ne < pos or ns > pos) return;
    if (ns >= pos and ne <= pos) {
        tree[ni].freq++;
        tree[ni].sum += val;
        return;
    }
    int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
    update(pos, val, lf, ns, mid);
    update(pos, val, rt, mid + 1, ne);
    tree[ni].freq = tree[lf].freq + tree[rt].freq;
    tree[ni].sum = tree[lf].sum + tree[rt].sum;
}


void doWork() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i] , all[i] = Copy[i] = v[i];
    allc = n;
    sort(all , all + allc);
    allc = unique(all , all + allc) - all;
    for (int i = 0; i < n; ++i) v[i] = lower_bound(all , all + allc , v[i]) - all;
    /***********************/
    init();
    ll ans = 0;
    for(int i = n - 1 ; ~i ; --i) {
        ll x = Copy[i];
        ll y = x + 2;
        y = lower_bound(all , all + allc , y) - all;
        pii Get = query(y , allc - 1);
        ans += Get.f - Get.s * x; // y >= x + 2
        y = x - 1;
        y = lower_bound(all , all + allc , y) - all;
        Get = query(y , allc - 1);
        pii allRange = query(0 , allc - 1);
        ans += (allRange.f - Get.f) - (allRange.s - Get.s) * x; // y <= x - 2
        update(lower_bound(all , all + allc , x) - all , Copy[i]);
    }
    cout<<fixed<<setprecision(0)<< ans << '\n';
}

int main() {
    FAST
    ll tc = 1;
//    cin >> tc;
    while (tc--) doWork();
}
/*
 * الحمد لله
 */