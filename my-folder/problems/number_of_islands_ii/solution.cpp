class Solution {
public:
    
    const static int N = 1e4+7;
    
    vector<vector<int>> mat;
    
    
    
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
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,1,-1};
    
    int n,m;
    
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    map<pair<int,int>,int> mp;
    
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        swap(n,m);
        this->n = n;
        this->m = m;
        mat = vector<vector<int>>(n,vector<int>(m,0));
        int id = 0;
        for(int i = 0 ; i<positions.size() ; i++){
            mp[{positions[i][0],positions[i][1]}] = id++;
        }
        
        DSU dsu;
        
        dsu.init(positions.size());
        
        vector<int> ans;
        
        int have = 0;
        
        for(int i = 0 ; i<positions.size() ; i++){
            int x = positions[i][0];
            int y = positions[i][1];
            have+=(1-mat[x][y]);
            mat[x][y] = 1;
            int old = dsu.nSets;
            for(int j = 0 ; j<4 ; j++){
                int newX = x+Xs[j];
                int newY = y+Ys[j];
                if(!valid(newX,newY)) continue;
                if(mat[newX][newY]==0) continue;
                dsu.join(mp[{x,y}],mp[{newX,newY}]);
            }
            int now = dsu.nSets;
            ans.push_back(have-(old-now));
            have = ans.back();
        }
        return ans;
        
    }
};