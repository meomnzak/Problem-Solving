class Solution {
public:
    string s;
    vector<string> wordDict;
    const static int N = 302;
    int meme[N];
    int n;
    
    int solve(int idx){
        if(idx<0) return true;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 0;
        for(string word: wordDict){
            if(idx>=word.length() - 1){
                string temp = s.substr(idx-word.size()+1,word.size());
                if(temp==word && solve(idx-word.size())){
                    ret = 1;
                    break;
                }
            }
        }
        
        return ret;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(meme,-1,sizeof(meme));
        n = s.size();
        this->s = s;
        this->wordDict = wordDict;
        return solve(n-1);
    }
};