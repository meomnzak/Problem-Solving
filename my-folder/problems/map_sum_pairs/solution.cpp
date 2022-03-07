class MapSum {
public:
    const static int N = 200;
    int nxt[N][26],nNodes = 0, cnt[N];
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        cnt[nNodes] = 0;
        return nNodes++;
    }
    
    int root;
    map<string,int> mp;
    MapSum() {
        nNodes = 0;
        root = createNode();
    }
    
    void insert(string key, int val) {
        int cur = root;
        int prev = mp[key];
        mp[key] = val;
        for(int i = 0 ; i<key.size() ; i++){
            int &child = nxt[cur][key[i]-'a'];
            if(child==-1)
                child = createNode();
            cnt[child]-=prev;
            cnt[child]+=val;
            cur = child;
        }
       
    }
    
    int sum(string prefix) {
        int cur = root;
        for(int i = 0 ; i<prefix.size() ; i++){
            int &child = nxt[cur][prefix[i]-'a'];
            if(child==-1) return 0;
            cur = child;
        }
        return cnt[cur];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */