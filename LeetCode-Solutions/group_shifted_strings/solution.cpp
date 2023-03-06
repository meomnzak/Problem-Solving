class Solution {
public:
    
    const static int N = 5003;
    
    struct DSU{
        int par[N],sz[N],nSets;
        void init(int n){
            iota(par,par+n,0);
            fill(sz,sz+n,1);
            nSets = n;
        }
        int find(int u){
            return u==par[u] ? u : par[u] = find(par[u]);
        }
        bool join(int u,int v){
            u = find(u);
            v = find(v);
            if(u==v) return false;
            if(sz[u]>sz[v]) swap(u,v);
            sz[v]+=sz[u];
            par[u] = v;
            nSets--;
            return true;
        }
    };
    
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();
        DSU dsu;
        dsu.init(n*30);
        unordered_map<string,int> mp;
        int id = 0;
        for(int i = 0 ; i<n ; i++){\
            string first = strings[i];
            string cur = strings[i];
            if(mp.find(cur)==mp.end()){
                mp[cur] = id++;
            }
            bool isZ = false;
            for(int j = 0 ; j<26 ; j++){
                for(int k = 0 ; k<cur.size() ; k++){
                    cur[k] = (char) ((cur[k]+1)%26);
                }
                if(mp.find(cur)==mp.end()){
                    mp[cur] = id++;
                }
                dsu.join(mp[first],mp[cur]);
            }
        }
        
        unordered_map<int,int> indices;
        id = 0;
        vector<vector<string>> ans;
        
        for(int i = 0 ; i<n ; i++){
            string cur = strings[i];
            int par = dsu.find(mp[cur]);
            if(indices.find(par)==indices.end()){
                indices[par] = id++;
                ans.push_back({});
            }
            ans[indices[par]].push_back(cur);
        }
        return ans;
        
    }
};