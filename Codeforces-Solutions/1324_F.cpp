#include <bits/stdc++.h>


#define endl '\n'


using namespace std;

typedef long long ll;

const int N = 2e5+7;

int arr[N];
int n;

vector<int> adj[N];

int dp[N];

void dpOnce(int u, int p){
    dp[u] = arr[u];
    for(auto v : adj[u]){
        if(v!=p){
            dpOnce(v,u);
            dp[u]+=max(dp[v],0);
        }
    }
}

int ans[N];

void rerooting(int u, int p){
    ans[u] = dp[u];
    for(auto v: adj[u]){
        if(v!=p){
            dp[u]-=max(0,dp[v]);
            dp[v]+=max(0,dp[u]);
            rerooting(v,u);
            dp[v]-=max(0,dp[u]);
            dp[u]+=max(0,dp[v]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        if(arr[i]==0){
            arr[i] = -1;
        }
    }

    int u,v;
    for (int i = 0; i < n-1; ++i) {
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dpOnce(0,-1);
    rerooting(0,-1);
    for(int i = 0 ; i<n ; i++){
        cout<<ans[i]<<" ";
    }
}