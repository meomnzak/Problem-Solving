#include <bits/stdc++.h>


using namespace std;


vector<vector<int>> adjList;
vector<int> color;

void bfs(int s){
    queue<int> q;
    q.push(s);
    int cur = s;
    color[s] = 1;
    while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 0 ; i<(int)adjList[cur].size() ; i++){
                if(color[adjList[cur][i]] == -1){
                    color[adjList[cur][i]] = 1 - color[cur];
                    q.push(adjList[cur][i]);
                }
            }
                
    }

}


int main(){
    int n;
    cin>>n;
    int u,v;
    adjList = vector<vector<int>>(n+3);
    color = vector<int> (n+3,-1);
    for(int i =  0 ;i<n-1 ; i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    int ones = -1;
    for(int i = 1 ; i<=n ; i++){
        if(color[i]==1){
            ones++;
        }
    }
   long long count = 0;
    for(int i = 1 ; i<=n ; i++){
        if(color[i]==1){
            count += (n-1)-adjList[i].size();
            count-=ones;
        }
    }
    cout<<count<<endl;
    return 0;
}