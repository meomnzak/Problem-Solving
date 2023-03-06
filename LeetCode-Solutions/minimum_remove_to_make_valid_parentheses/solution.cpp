class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        vector<int> banned(s.size(),0);
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]==')'){
                if(open>0){
                    open--;
                }else{
                    banned[i] = 1;
                }
            }else if(s[i]=='('){
                open++;
            }
        }
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(open==0) break;
            if(s[i]=='('){
                banned[i] = 1;
                open--;
            }
        }
        
        string ans = "";
        
        for(int i = 0 ; i<s.size() ; i++){
            if(banned[i]) continue;
            ans+=s[i];
        }
        
        return ans;
    }
};