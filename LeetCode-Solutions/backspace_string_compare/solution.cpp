class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        string s1 = "";
        string s2 = "";
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]=='#'){
                if(st1.size()>0) st1.pop();
            }else{
                st1.push(s[i]);
            }
        }
        while(st1.size()>0){
            s1+=st1.top();
            st1.pop();
        }
        reverse(s1.begin(),s1.end());
        for(int i = 0 ; i<t.size() ; i++){
            if(t[i]=='#'){
                if(st2.size()>0) st2.pop();
            }else{
                st2.push(t[i]);
            }
        }
        while(st2.size()>0){
            s2+=st2.top();
            st2.pop();
        }
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};