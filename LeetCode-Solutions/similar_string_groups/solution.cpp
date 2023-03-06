class Solution {
public:
    
    const static int N = 303;
    
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
        
        bool join(int u, int v){
            u = find(u), v = find(v);
            if(u==v) return false;
            if(sz[u]>sz[v]) swap(u,v);
            nSets--;
            sz[v]+=sz[u];
            par[u] = v;
            return true;
        }
        
    } dsu;
    
    bool checkSimilar(string &s , string &t){
        int diff = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]!=t[i]) diff++;
        }
        return (diff<=2);
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        
        dsu.init(n);
        
        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                if(checkSimilar(strs[i],strs[j])){
                    dsu.join(i,j);
                }
            }
        }
        return dsu.nSets;
    }
};