class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        unordered_map<int,int> mp;
        for(int i = 0  ; i<indices.size() ; i++){
            mp[indices[i]] = i;
        }
        int idx = 0;
        string sol = "";
        for(int i = 0 ; i<s.size() ;){
            if(mp.find(i)!=mp.end()){
                int idx = mp[i];
                if(sources[idx].size()+i<=s.size()){
                    string str = s.substr(i,sources[idx].size());
                    if(str==sources[idx]){
                        sol+=targets[idx];
                        i+=sources[idx].size();
                        continue;
                    }
                }
            }
            sol+=s[i];
            i++;
        }   
        return sol;
    }
};