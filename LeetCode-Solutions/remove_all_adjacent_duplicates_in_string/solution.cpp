class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0 ; i<s.size() ; i++){
            if(st.size()>0 && st.top()==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        
        string newString = "";
        while(st.size()>0){
            newString+=st.top();
            st.pop();
        }
        
        reverse(newString.begin(),newString.end());
        return newString;
        
    }
};