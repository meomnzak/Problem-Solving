class StreamChecker {
public:
    
    const static int N = 1e5+6;
    
    int nxt[N][26], ok[N], nNodes;
    int root;
    
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        ok[nNodes] = 0;
        return nNodes++;
    }
    
    void init(){
        nNodes = 0;
        root = createNode();
    }
    
    void addString(string &s){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'a'];
            if(child==-1)
                child = createNode();
            cur = child;
        }
        ok[cur] = 1;
    }
    
    bool find(deque<char> &s){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'a'];
            if(child==-1)
                return 0;
            if(ok[child]){
                return 1;
            }
            cur = child;
        }
        return 0;
    }
    
    deque<char> vec;
    
    StreamChecker(vector<string>& words) {
        init();
        vec.clear();
        for(int i = 0; i<words.size() ; i++){
            string s = words[i];
            reverse(s.begin(),s.end());
            addString(s);
        }
    }
    
    
    bool query(char letter) {
        vec.push_front(letter);
        return find(vec);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */