#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

const int N = 2e5+8;


int cost[N], minCost[N];
int vis[N],vid,lowlink[N], dfst[N], tim, cmpId[N], cmpCnt, stck[N], stcksz;
vector<int> adj[N];

int n,m;

void sccdfs(int u){
    cmpId[u] = -1;
    dfst[u] = lowlink[u] = tim++;
    stck[stcksz++] = u;
    vis[u] = vid;
    for(auto v: adj[u]){
        if(vis[v]!=vid){
            sccdfs(v);
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }else if(cmpId[v]==-1){
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }
    }

    int mini = 1e9;
    if(lowlink[u]==dfst[u]){
        do{
            mini = min(mini,cost[stck[stcksz-1]]);
            cmpId[stck[--stcksz]] = cmpCnt;
        }while(stck[stcksz]!=u);
        minCost[cmpCnt] = mini;
        ++cmpCnt;
    }

}

int outDegree[N];

int tarjan(){
    vid++;
    tim = cmpCnt = stcksz = 0;
    for(int i = 0  ; i<n ; i++){
        if(vis[i]!=vid) sccdfs(i);
    }

    for(int u = 0 ; u<n ; u++){
        for(auto v: adj[u]){
            if(cmpId[u]==cmpId[v]) continue;

            outDegree[cmpId[u]]++;
        }
    }
    int ans = 0;

    for(int i = 0 ; i<cmpCnt ; i++){
        if(outDegree[i]==0){
            ans+=minCost[i];
        }
    }

    return ans;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cin>>cost[i];
    }
    int v;
    for(int i = 0  ; i<n; i++){
        cin>>v;
        v--;
        adj[i].push_back(v);
    }
    cout<<tarjan()<<endl;
}