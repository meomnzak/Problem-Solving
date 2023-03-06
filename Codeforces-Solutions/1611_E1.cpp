#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+7;


vector<int> adj[N];

vector<int> friends;

int dis[N];

int n,k;

void bfs(int src){
    queue<pair<int,int>> q;
    dis[src] = 0;
    q.push({src,-1});
    while(!q.empty()){
        int u = q.front().first;
        int p = q.front().second;
        q.pop();
        for(auto v : adj[u]){
            if(v!=p){
                dis[v] = dis[u]+1;
                q.push({v,u});
            }
        }
    }
}


int vis[N];

int disAgain[N];

void again(){
    queue<int> q;
    for (int i = 0; i < friends.size(); ++i) {
        q.push(friends[i]);
        vis[friends[i]] = 1;
        disAgain[friends[i]] = 0;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(vis[v]==0){
                disAgain[v] = disAgain[u]+1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;

    while(t--){
        cin>>n>>k;
        for (int i = 0; i < n+3; ++i) {
            dis[i] = 0;
            disAgain[i] = 0;
            adj[i].clear();
            vis[i] = 0;
        }
        friends.clear();
        int num;
        for (int i = 0; i < k; ++i) {
            cin>>num;
            num--;
            friends.push_back(num);
        }
        int u,v;
        for (int i = 0; i < n-1; ++i) {
            cin>>u>>v;
            u--;
            v--;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        bfs(0);
       again();
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if(adj[i].size()==1){
                if(dis[i]<disAgain[i]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;

}
