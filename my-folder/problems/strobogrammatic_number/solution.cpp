class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> mp;
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['9'] = '6';
        mp['8'] = '8';
        int n = num.size();
        for(int i = 0 ; i<=n/2 ;i++){
            if(mp.find(num[i])==mp.end()){
                return false;
            }else{
                char expect = mp[num[i]];
                if(expect!=num[n-i-1]) return false;
            }
        }
        return true;
    }
};