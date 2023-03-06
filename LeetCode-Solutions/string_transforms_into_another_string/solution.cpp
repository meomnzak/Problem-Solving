class Solution {
public:
    
    const static int N = 27;
    
    vector<int> adj[N];
    
    bool isCycle = false;
    
    int color[N];
    
    bool canConvert(string str1, string str2) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i<str1.size() ; i++){
            int u = str1[i]-'a';
            int v = str2[i]-'a';
            mp[v]++;
            if(adj[u].size()==0){
                adj[u].push_back(v);
            }else if(adj[u].size()==1){
                if(adj[u][0]!=v) return false;
            }
        }
        
        if(mp.size()<26) return true;
        
        for(int i = 0 ; i<str1.size() ; i++){
            int u = str1[i]-'a';
            if(color[u]==0){
                dfs(u);
            }
        }
        
        
        
        return !isCycle;
        
    }
    
    void dfs(int u){
        color[u] = 1;
        for(auto v: adj[u]){
            if(u==v) continue;
            if(color[v]==1){
                isCycle = true;
            }else if(color[v]==0){
                dfs(v);
            }
        }
        color[u] = 2;
    }
    
    
    
};