#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

const int N = 2e5+7;

ll cost[N], minCost[N];

int vis[N], vid, lowlink[N], dfst[N], tim, cmpId[N], cmpCnt, stck[N], stcksz;

vector<int> adj[N];

int n;

void sccdfs(int u){
    cmpId[u] = -1;
    dfst[u] = lowlink[u] = tim++;
    stck[stcksz++] = u;
    vis[u]= vid;
    for(auto v: adj[u]){
        if(vis[v]!=vid){
            sccdfs(v);
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }else if(cmpId[v]==-1){
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }
    }
    ll mini = 1e9;
    if(lowlink[u]==dfst[u]){
        do{
            mini = min(mini,cost[stck[stcksz-1]]);
            cmpId[stck[--stcksz]] = cmpCnt;
        }while(stck[stcksz]!=u);
        minCost[cmpCnt] = mini;
        cmpCnt++;
    }
}

void tarjan(){
    vid++;
    tim = cmpCnt = stcksz = 0;
    for(int i = 0 ; i<n ; i++){
        if(vis[i]!=vid){
            sccdfs(i);
        }
    }
}

int ways[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cin>>cost[i];
    }
    int m;
    cin>>m;
    int x,y;
    for(int i = 0 ; i<m ; i++){
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
    }

    tarjan();

    ll ans = 0;
    for(int i = 0 ;i<cmpCnt ; i++){
        ans+=minCost[i];
    }

    for(int i = 0 ; i<n ; i++){
        if(cost[i]==minCost[cmpId[i]]){
            ways[cmpId[i]]++;
        }
    }

     ll numOfways = 1;

    const int MOD = 1e9+7;

    for(int i = 0 ; i<cmpCnt ; i++){
        numOfways = ((numOfways%MOD) * (ways[i]%MOD)) %MOD;
    }

    cout<<ans<<" "<<numOfways<<endl;


}