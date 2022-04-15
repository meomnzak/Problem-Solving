class Solution {
public:
    
    
    const static int N = 34;
    
    int meme[N][N];
    string s;
    string p;
    
    bool solve(int stringIndex, int regexIndex){
        if(stringIndex==s.size() && regexIndex==p.size()) return true;
        if(regexIndex==p.size()) return false;
        int &ret = meme[stringIndex][regexIndex];
        if(~ret) return ret;
        ret = 0;
        if(stringIndex==s.size()){
            if(regexIndex+1<p.size() && p[regexIndex+1]=='*')
                ret|=solve(stringIndex,regexIndex+2);
        }else{
            if(regexIndex+1<p.size() && p[regexIndex+1]=='*'){
                if(p[regexIndex] == '.' || s[stringIndex]==p[regexIndex]){
                    ret|=solve(stringIndex+1,regexIndex);
                    ret|=solve(stringIndex+1,regexIndex+2);
                     ret|=solve(stringIndex,regexIndex+2);
                }else{
                    ret|=solve(stringIndex,regexIndex+2);
                }
            }else{
                if(p[regexIndex]=='.' || p[regexIndex]==s[stringIndex]){
                    ret|= solve(stringIndex+1,regexIndex+1);
                }
            }      
        }
      
        return ret;
        
    }
    
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        memset(meme,-1,sizeof(meme));
        return solve(0,0);
    }
    
    
};