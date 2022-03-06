class Solution {
public:
    const static int N = 2e3+6;
    int vis[N];
    bool cycle = false;
    vector<int> adj[N];
    int n;
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0 ; i<prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        n = numCourses;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i])
                dfs(i);
        }
        if(cycle) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(int u){
        vis[u] = 1;
        for(auto v: adj[u]){
            if(vis[v]==1) cycle = 1;
            if(!vis[v])
                dfs(v);
        }
        ans.push_back(u);
        vis[u] = 2;
    }
};