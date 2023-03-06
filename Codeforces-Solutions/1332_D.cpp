#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;


//int dp[501][501];
//
//int a[501][501];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
//    int n,m;
//    cin>>n>>m;
//    for (int i = 1; i <=n ; ++i) {
//        for (int j = 1; j <=m ; ++j) {
//            cin>>a[i][j];
//        }
//    }
//    dp[0][1] = a[1][1];
//
//    for (int i = 1; i <=n ; ++i) {
//        for (int j = 1; j <=m ; ++j) {
//            dp[i][j] = max(dp[i-1][j]&a[i][j],dp[i][j-1]&a[i][j]);
//        }
//    }
//
//    cout<<dp[n][m]<<endl;
        int k;
        cin>>k;
        int num = 1<<17;
        cout<<2<<" "<<3<<endl;
        cout<<num+k<<" "<<num<<" "<<0<<endl;
        cout<<k<<" "<<num+k<<" "<<k<<endl;
}