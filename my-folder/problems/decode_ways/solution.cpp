class Solution {
public:
    map<string,int> mp;
    string s;
    const static int N = 103;
    int n;
    int meme[N];
    
    int solve(int i){
        if(i==n) return 1;
        int &ret = meme[i];
        if(~ret) return ret;
        ret = 0;
        string temp = "";
        temp+=s[i];
        if(mp[temp]==1){
            ret += solve(i+1);
        }
        if(i+1<n){
            temp+=s[i+1];
            if(mp[temp]==1){
                ret += solve(i+2);
            }
        }
        return ret;
    }
    
    
    int numDecodings(string s) {
        memset(meme,-1,sizeof(meme));
        this->s = s;
        n = s.size();
        for(int i = 1 ; i<=26 ; i++){
            mp[to_string(i)] = 1;
        }
        return solve(0);
    }
};