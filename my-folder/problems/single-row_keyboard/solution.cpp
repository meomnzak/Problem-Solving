class Solution {
public:
    int calculateTime(string keyboard, string word) {
        
        unordered_map<char,int> mp;
        for(int i = 0 ; i<keyboard.size() ; i++){
            mp[keyboard[i]] = i;
        }
        int prev = 0;
        int ans = 0;
        for(int i = 0 ; i<word.size() ; i++){
            ans+= abs(mp[word[i]]-prev);
            prev = mp[word[i]];
        }
        return ans;
        
    }
};