#include <bits/stdc++.h>


using namespace std;

vector<vector<pair<long long,long long>>> adjList;
vector<bool> vis;
long long cost = 0;

long long maxx = 0;

void dfs(long long u,long long far){
    if(far>maxx){
        maxx= far;
    }
    vis[u] = 1;
    for(long long i = 0 ; i<adjList[u].size() ; i++){
        long long v = adjList[u][i].first;
        if(vis[v]==0){
            cost+=adjList[u][i].second;
            dfs(v,far+adjList[u][i].second);
        }
    }
}


int main(){
    long long n;
    cin>>n;
    long long u,v,ss;
    adjList = vector<vector<pair<long long,long long>>> (n+3);
    vis = vector<bool> (n+3,0);
    for(long long i = 0 ; i<n-1 ; i++){
        cin>>u>>v>>ss;
        adjList[u].push_back(make_pair(v,ss));
        adjList[v].push_back(make_pair(u,ss));
    }
    dfs(1,0);
    cout<<cost*2-maxx<<endl;
    return 0;
}