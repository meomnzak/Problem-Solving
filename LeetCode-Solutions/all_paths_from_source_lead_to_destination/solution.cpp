class Solution {
public:
    

    const static int N = 1e4+6;
    int outDegree[N];
    vector<int> adj[N];
    int color[N];
    int dist;
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        dist = destination;
        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            outDegree[edges[i][0]]++;
        }
       return dfs(source);
    }
    
    

    
    bool dfs(int u){
        if(outDegree[u]==0){
            if(u==dist) return true;
            return false;
        }
        int state = 1;
        color[u] = 1;
        for(auto v: adj[u]){
            if(color[v]==1) return state&=false;
            if(color[v]==0){
                state&=dfs(v);
            }
        }
        color[u] = 2;
        return state;
    }
    
};