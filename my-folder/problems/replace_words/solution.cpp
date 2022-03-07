class Solution {
public:
    const static int N = 1e5+7;
    int nxt[N][26], ok[N], nNodes = 0;
    
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        ok[nNodes] = 0;
        return nNodes++;
    }
    
    int root;
    
    void init(){
        nNodes = 0;
        root = createNode();
    }
    
    void addString(string s){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'a'];
            if(child==-1)
                child = createNode();
            cur = child;
        }
        ok[cur] = 1;
    }
    
    
    string find(string s){
        int cur = root;
        string sol = "";
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'a'];
            if(child==-1)
                return s;
            sol+=s[i];
            if(ok[child]==1)
                return sol;
            cur = child;
        }
        
        return s;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        init();
        for(int i = 0 ; i<dictionary.size() ; i++){
            addString(dictionary[i]);
        }
        stringstream ss(sentence);
        string word;
        string finale = "";
        while(ss>>word){
            finale+=find(word);
            finale+=" ";
        }
        finale.pop_back();
        return finale;
    }
};