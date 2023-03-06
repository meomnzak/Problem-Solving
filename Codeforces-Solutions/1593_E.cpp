#include <bits/stdc++.h>


#define endl '\n'



using namespace std;

typedef long long ll;


const int N = 4e5+6;

int deg[N];

vector<int> adj[N];


int n,k;

void bfs(){
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if(deg[i]==1){
            q.push(i);
        }
    }
    int lvl = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int u = q.front();
            q.pop();
            deg[u]--;
            for(auto v: adj[u]){
                deg[v]--;
                if(deg[v]==1){
                    q.push(v);
                }
            }
        }
        lvl++;
        if(lvl==k) break;
    }
    while(!q.empty()){
        deg[q.front()] = 1;
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){

        cin>>n>>k;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        memset(deg,0,sizeof(deg));
        int u,v;
        for (int i = 0; i < n-1; ++i) {
            cin>>u>>v;
            u--;
            v--;
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(deg[i]>0) ans++;
        }
        cout<<ans<<endl;

    }
}