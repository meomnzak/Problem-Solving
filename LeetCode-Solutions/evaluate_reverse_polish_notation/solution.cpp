class Solution {
public:
    bool isOperand(string ch){
        return (ch=="+"||ch=="-"||ch=="*"||ch=="/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i = 0 ; i<n ; i++){
            if(!isOperand(tokens[i])){
                st.push(stoi(tokens[i]));
            }else{
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int res = 0;
                if(tokens[i]=="+"){
                    res = first+second;
                }else if(tokens[i]=="-"){
                    res = first-second;
                }else if(tokens[i]=="*"){
                    res = first*second;
                }else if(tokens[i]=="/"){
                    res = first/second;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};