class Solution {
public:
    void reverseString(vector<char>& s) {
        rev(s,0);
    }
    void rev(vector<char> &s, int idx){
        if(idx==s.size()/2) return;
        swap(s[idx],s[s.size()-idx-1]);
        rev(s,idx+1);
    }
};