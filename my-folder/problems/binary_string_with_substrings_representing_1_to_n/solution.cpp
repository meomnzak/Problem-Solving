class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = n ; i>=0 ; i--){
            string go = convertToBinary(i);
            if(s.find(go)==string::npos) return false;
        }
        return true;
    }
    
    string convertToBinary(int n){
        string s = "";
        while(n!=0){
            s+= ((n%2)+'0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    
};