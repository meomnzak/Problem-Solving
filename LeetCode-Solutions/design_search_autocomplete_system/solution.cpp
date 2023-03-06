class AutocompleteSystem {
public:
    const static int N = 1e4+6;
    int nxt[N][150],nNodes = 0;
    vector<pair<int,string>> cnt[N];
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        cnt[nNodes].clear();
        return nNodes++;
    }
    int root;
    void init(){
        nNodes = 0;
        root = createNode();
    }
    
    bool static mySort(pair<int,string> p1 , pair<int,string>p2){
        if(p1.first!=p2.first) return p1.first>p2.first;
        return p1.second<p2.second;
    }
    
    void increament(string s,int child, int num){
        bool flag = false;
        for(int i = 0 ; i<cnt[child].size() ; i++){
            if(cnt[child][i].second==s){
                cnt[child][i].first+=num;
                flag = true;
                break;
            }
        }
        if(!flag) cnt[child].push_back({num,s});
        sort(cnt[child].begin(),cnt[child].end(),mySort);
    }
    
    void addString(string s, int num){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]];
            if(child==-1)
                child = createNode();
            increament(s,child,num);
            cur = child;
        }
    }
    
    vector<string> find(string s){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]];
            if(child==-1)
                return {};
            cur = child;
        }
        auto vec = cnt[cur];
        vector<string> sol;
        for(int i = 0 ; i<min(3,(int)vec.size()) ; i++){
            sol.push_back(vec[i].second);
        }
        return sol;
    }
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        init();
        for(int i = 0 ; i<sentences.size() ; i++){
            addString(sentences[i],times[i]);
        }
    }
    string temp = "";
    vector<string> input(char c) {
        if(c=='#'){
            addString(temp,1);
            temp = "";
            return {};
        }else{
            temp+=c;
            return find(temp);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */