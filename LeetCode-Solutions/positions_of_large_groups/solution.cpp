class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> vec;
        int n = s.size();
        int st = 0;
        int en = 0;
        for(int i = 0 ; i<n-1 ; i++){
            if(s[i]==s[i+1]){
                en = i+1;
            }else{
                if(en-st+1>=3){
                    vec.push_back({st,en});
                }
                st = i+1;
                en = i+1;
            }
        }
        if(en-st+1>=3){
            vec.push_back({st,en});
        }
        return vec;
        
    }
};