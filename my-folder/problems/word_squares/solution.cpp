class Solution {
public:
    const static int N = 5e3+7;
    int nxt[N][26], nNodes = 0;
    vector<int> indices[N];
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        indices[nNodes].clear();
        return nNodes++;
    }
    int root;
    
    void init(){
        nNodes = 0;
        root =createNode();
    }
    
    void addString(string s, int idx){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'a'];
            if(child==-1)
                child = createNode();
            indices[child].push_back(idx);
            cur = child;
        }
    }
    
    vector<int> find(string s){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'a'];
            if(child==-1)
                return {};
            cur = child;
        }
        return indices[cur];
    }
    
    vector<vector<string>> ans;
    vector<string> vec;
    
    int n;
    
    void backtrack(int idx, vector<string>& words){
        if(vec.size()==n){
            ans.push_back(vec);
            return;
        }
        string s = "";
        for(int i = 0 ; i<vec.size() ; i++){
            s+=vec[i][idx];
        }
        vector<int> indices = find(s);
        
        for(int i = 0 ; i<indices.size() ; i++){
            vec.push_back(words[indices[i]]);
            backtrack(idx+1,words);
            vec.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        init();
        for(int i = 0 ; i<words.size() ; i++){
            addString(words[i], i);
        }
        n = words[0].size();
        for(int i = 0 ; i<words.size() ; i++){
            vec.push_back(words[i]);
            backtrack(1,words);
            vec.pop_back();
        }
        return ans;
    }
    
};