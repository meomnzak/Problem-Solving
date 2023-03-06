class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i<s.size() ; i++){
            if(st.size()>0 && ((s[i]=='}'&& st.top()=='{') || (s[i]==')'&& st.top()=='(') || (s[i]==']'&& st.top()=='[')) ){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return (st.size()==0);
    }
};