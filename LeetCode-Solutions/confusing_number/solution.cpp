class Solution {
public:
    bool confusingNumber(int n) {
        map<char,char> mp;
        string num = to_string(n);
        mp['0'] = '0';
        mp['1'] = '1';
        mp['2'] = 'X';
        mp['3'] = 'X';
        mp['4'] = 'X';
        mp['5'] = 'X';
        mp['6'] = '9';
        mp['7'] = 'X';
        mp['8'] = '8';
        mp['9'] = '6';
        string res = num;
        for(int i = 0 ;i<res.size() ; i++){
            res[i] = mp[res[i]];
        }
        reverse(res.begin(),res.end());
        bool flag = false;
        for(int i = 0 ; i<num.size() ; i++){
            if(res[i]=='X') return false;
            if(num[i]!=res[i]) flag = true;
        }
        
        return flag;
        
    }
};