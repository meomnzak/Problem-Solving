class Solution {
public:
    
    const static int N = 6004;
    
    struct DSU{
        int par[N],sz[N],nSets;
        void init(int n){
            fill(sz,sz+n,1);
            iota(par,par+n,0);
            nSets = n;
        }
        
        int find(int u){
            return u==par[u] ? u : par[u] = find(par[u]);
        }
        
        bool join(int u, int v){
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
    
    
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;
        unordered_map<string,int> mp;
        int id = 0;
        for(int i = 0 ; i<similarPairs.size() ; i++){
            string pair1 = similarPairs[i][0];
            string pair2 = similarPairs[i][1];
            if(mp.find(pair1)==mp.end()){
                mp[pair1] = id++;
            }
            if(mp.find(pair2)==mp.end()){
                mp[pair2] = id++;
            }
        }
        for(int i = 0 ; i<sentence1.size() ; i++){
           if(mp.find(sentence1[i])==mp.end()){
               mp[sentence1[i]]= id++;
           }
             if(mp.find(sentence2[i])==mp.end()){
               mp[sentence2[i]]= id++;
           }
        }
        
        DSU dsu;
        dsu.init(mp.size());
        
        for(int i = 0 ; i<similarPairs.size() ; i++){
            string pair1 = similarPairs[i][0];
            string pair2 = similarPairs[i][1];
            dsu.join(mp[pair1],mp[pair2]);
        }
        
        for(int i = 0 ; i<sentence1.size() ; i++){
            int u = mp[sentence1[i]];
            int v = mp[sentence2[i]];
            u = dsu.find(u), v = dsu.find(v);
            if(u!=v && sentence1[i]!=sentence2[i]){
                return false;
            }
        }
        return true;
        
    }
};