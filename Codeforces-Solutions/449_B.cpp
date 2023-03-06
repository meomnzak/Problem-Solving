#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+7, M=3e5+7, K=1e5+7;

vector<pair<ll,int>> adj[N];

ll dis[N];

void dijkstra(int src){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    memset(dis,'?',sizeof(dis));
    dis[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if(d!=dis[u]) continue;
        for(auto e : adj[u]){
            int v = e.first;
            int c = e.second;
            ll nd = dis[u]+c;
            if(nd<dis[v]){
                dis[v] = nd;
                pq.push({nd,v});
            }
        }
    }
}


struct edge{
    int from,to;
    ll cost;
};

int ecnt = 0;

edge edgeList[2*M];
edge trains[K];

int reach[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,c;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v>>c;
        u--;
        v--;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
        edgeList[ecnt++] = {u,v,c};
        edgeList[ecnt++] = {v,u,c};
    }

    for (int i = 0; i < k; ++i) {
        cin>>u>>c;
        u--;
        trains[i] = {0,u,c};
        adj[0].push_back({u,c});
        adj[u].push_back({0,c});
    }
    dijkstra(0);

    for(int i = 0 ; i<ecnt ; i++){
        edge e = edgeList[i];
        if(dis[e.from]+e.cost==dis[e.to]){
            reach[e.to] = 1;
        }
    }
    int remove = 0;
    for(int i = 0 ; i<k ; i++){
        edge e = trains[i];
        if(reach[e.to] || dis[e.from]+e.cost!=dis[e.to]){
            remove++;
        }else{
            reach[e.to] = 1;
        }
    }
    cout<<remove<<endl;


    return 0;

}
