class WordDictionary {
public:
    const static int N = 3e5+6;
    int nxt[N][26], ok[N], nNodes = 0;
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        ok[nNodes] = 0;
        return nNodes++;
    }
    int root;
    WordDictionary() {
        nNodes = 0;
        root = createNode();
    }
    
    void addWord(string word) {
        int cur = root;
        for(int i = 0 ; i<word.size() ; i++){
            int &child = nxt[cur][word[i]-'a'];
            if(child==-1)
                child = createNode();
            cur = child;
        }
        ok[cur] = 1;
    }
    bool go;
    
    bool dfs(int cur, int idx,string &word){
        if(idx==word.size()){
            return 0;
        }
        bool ret = 0;
        char ch = word[idx];
        if(word[idx]=='.'){
            for(int i = 0 ; i<26 ; i++){
                int child = nxt[cur][i];
                if(child!=-1){
                     if(idx==word.size()-1){
                        ret|=ok[child];
                    }
                    ret|=dfs(nxt[cur][i],idx+1,word);
                }
            }
        }else{
            int child = nxt[cur][word[idx]-'a'];
            if(child==-1){
                ret|=0;
            }else{
                if(idx==word.size()-1){
                    ret|=ok[child];
                }
                ret|=dfs(nxt[cur][word[idx]-'a'],idx+1,word);
            }
        }
        return ret;
    }
    
    
    bool search(string word) {
        return dfs(root,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */