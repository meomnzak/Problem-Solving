#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

const int N = 1e6+7;


int vis[N], vid, lowlink[N], dfst[N], tim, cmpId[N], cmpCnt, stck[N], stcksz;
ll value[N];

vector<pair<int,int>> adj[N];

int n;

void sccdfs(int u){
    cmpId[u] = -1;
    dfst[u] = lowlink[u] = tim++;
    stck[stcksz++] = u;
    vis[u]= vid;
    for(auto e: adj[u]){
        int v = e.first;
        if(vis[v]!=vid){
            sccdfs(v);
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }else if(cmpId[v]==-1){
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }
    }
    if(lowlink[u]==dfst[u]){
        do{
            cmpId[stck[--stcksz]] = cmpCnt;
        }while(stck[stcksz]!=u);
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

ll calc(ll num){
    ll res = -1;
    ll low = 0, high = 1e9;
    while(low<=high){
        ll mid = low + (high-low)/2;
        ll cur = ((mid)*(mid+1))/2;
        if(cur<=num){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return num*(res+1) - ((res*(res+1)*(res+2))/6);
}

vector<pair<int,int>> adjSCC[N];

ll memo[N];

ll solve(int u){
    ll &ret = memo[u];
    if(~ret) return ret;
    ret = value[u];
    for(auto e: adjSCC[u]){
        int v = e.first;
        int c = e.second;
        ret = max(ret,value[u]+c+solve(v));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m;
    cin>>n>>m;
    int x,y,cst;
    for(int i = 0 ; i<m ; i++){
        cin>>x>>y>>cst;
        x--;
        y--;
        adj[x].push_back({y,cst});
    }
    int src;
    cin>>src;
    src--;
    tarjan();

    for(int u = 0 ; u<n ; u++){
        for(auto e: adj[u]){
            int v = e.first;
            int c = e.second;
            if(cmpId[u]==cmpId[v]) continue;
            adjSCC[cmpId[u]].push_back({cmpId[v],c});
        }
    }

    for(int u = 0 ; u<n ; u++){
        for(auto e: adj[u]){
            int v = e.first;
            int c = e.second;
            if(cmpId[u]==cmpId[v]){
                value[cmpId[u]]+=calc(c);
            }
        }
    }

    memset(memo,-1,sizeof(memo));
    cout<<solve(cmpId[src])<<endl;

}