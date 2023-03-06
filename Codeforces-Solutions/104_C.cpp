#include <bits/stdc++.h>


using namespace std;

vector<vector<int>> AdjList;
vector<int> vis;

void dfs(int u){
    vis[u] = 1;
    for(int i = 0 ; i<(int)AdjList[u].size() ; i++){
        if(!vis[AdjList[u][i]]){
            dfs(AdjList[u][i]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    AdjList = vector<vector<int>>(n+3);
    vis = vector<int>(n+3,0);
    int u,v;
    for(int i = 0 ; i<m ; i++){
        cin>>u>>v;
        AdjList[v].push_back(u);
        AdjList[u].push_back(v);
    }
    dfs(1);
    bool flag = true;
    for(int i = 1 ; i<=n ; i++){
        if(!vis[i]){
            flag = false;
            break;
        }
    }
  if(flag && n==m){
        cout<<"FHTAGN!"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}