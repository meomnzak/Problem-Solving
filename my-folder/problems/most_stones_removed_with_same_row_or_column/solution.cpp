class Solution {
public:
    const static int N = 1003;
    struct DSU{
        int par[N],sz[N],nSets;
        void init(int nNodes){
            nSets = nNodes;
            iota(par,par+nNodes,0);
            fill(sz,sz+nNodes,1);
        }
        int find(int u){
            return u==par[u] ? u : par[u] = find(par[u]);
        }
        bool join(int u, int v){
            u = find(u), v = find(v);
            if(u==v) return 0;
            if(sz[u]>sz[v]) swap(u,v);
            par[u] = v;
            sz[v]+=sz[u];
            nSets--;
            return 1;
        }
    };
    int removeStones(vector<vector<int>>& stones) {
        map<pair<int,int>,int> mp;
        int id = 0;
        for(int i = 0 ; i<stones.size() ; i++){
            if(mp.find({stones[i][0],stones[i][1]})==mp.end()){
                mp[{stones[i][0],stones[i][1]}] = id++;
            }
        }
        DSU dsu;
        dsu.init(stones.size());
        for(int i = 0 ; i<stones.size() ; i++){
            for(int j = i+1 ; j<stones.size() ; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dsu.join(mp[{stones[i][0],stones[i][1]}],mp[{stones[j][0],stones[j][1]}]);
                }
            }
        }
        
        return stones.size()-dsu.nSets;
        
        
    }
};