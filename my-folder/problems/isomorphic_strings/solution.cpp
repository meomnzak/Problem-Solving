class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> taken;
        for(int i = 0 ; i<s.size() ; i++){
            if(mp.find(s[i])==mp.end()){
                if(taken[t[i]]) return false;
                mp[s[i]] = t[i];
                taken[t[i]] = 1;
            }else{
                char excpected = mp[s[i]];
                if(excpected!=t[i]) return false;
            }
        }
        return true;
    }
};