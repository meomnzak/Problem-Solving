class Solution {
public:
    
    string s = "";
    int sz;
    vector<string> ans;
    void solve(int idx, int open, int close){
        if(idx==sz){
            ans.push_back(s);
            return;
        }
        if(open<sz/2){
            s+="(";
            solve(idx+1,open+1,close);
            s.pop_back();
        }
        if(open>close){
            s+=')';
            solve(idx+1,open,close+1);
            s.pop_back();
            
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        sz = n*2;
        solve(0,0,0);
        return ans;
    }
};