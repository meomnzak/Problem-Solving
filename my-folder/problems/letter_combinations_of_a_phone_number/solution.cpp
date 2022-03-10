class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        vector<string> vec = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,vec);
        return ans;
    }
    string word = "";
    void solve(int idx, string& digits, vector<string>&vec){
        if(idx==digits.size()){
            ans.push_back(word);
            return;
        }
        
        int cur = (digits[idx]-'0')-2;  
        for(int i = 0 ; i<vec[cur].size() ; i++){
            word+=vec[cur][i];
            solve(idx+1,digits,vec);
            word.pop_back();
        }
            
    }
};