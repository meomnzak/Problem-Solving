class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cur = 0;
        
        for(int i = 0 ; i<t.size() ; i++){
            if(cur<s.size() && t[i]==s[cur]){
                cur++;
            }
            
        }
        
        return (cur==s.size());
    }
};