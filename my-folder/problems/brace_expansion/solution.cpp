class Solution {
public:
    
    vector<vector<char>> vec;
    
    string s = "";
    
    vector<string> ans;
    
    void solve(int idx){
        if(idx==vec.size()){
            ans.push_back(s);
            return;
        }
        for(int i = 0 ; i<vec[idx].size() ; i++){
            s+=vec[idx][i];
            solve(idx+1);
            s.pop_back();
        }
    }
    
    vector<string> expand(string s) {
        
        for(int i = 0 ; i<s.size() ; i++){
            vector<char> cur;
            if(s[i]=='{'){
                while(s[i]!='}'){
                    if(isalpha(s[i])){
                        cur.push_back(s[i]);
                    }
                    i++;
                }
            }else{
                cur.push_back(s[i]);
            }
            vec.push_back(cur);
        }
        
        solve(0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};