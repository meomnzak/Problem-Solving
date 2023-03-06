#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;


const int N = 2e5+7;

int vis[N];

vector<int> adj[N];

int greatest = 0;

void dfs(int u){
    vis[u] = 1;
    greatest = max(greatest,u);
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n,m;
    cin>>n>>m;
    int u,v;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(!vis[i]){
            if(i>greatest){
                greatest = 0;
            }else{
                cnt++;
            }
            dfs(i);
        }
    }

    cout<<cnt-1<<endl;
    
}