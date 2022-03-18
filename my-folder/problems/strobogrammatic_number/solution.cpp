class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> mp;
        mp['6'] = '9';
        mp['9'] = '6';
        mp['1'] = '1';
        mp['0'] = '0';
        mp['8'] = '8';
        for(int i = 0 ; i<=num.size()/2 ; i++){
            if(mp.find(num[i])==mp.end()) return false;
            if(mp[num[i]]!=num[num.size()-i-1]) return false;
        }
        return true;
    }
};