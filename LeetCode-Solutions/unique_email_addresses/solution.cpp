class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(int i = 0 ; i<emails.size() ; i++){
            string s = "";
            string cur = emails[i];
            bool flag = true;
            bool plus = false; 
            for(int j = 0 ; j<cur.size() ; j++){
                if(flag==true){
                    if(cur[j]=='+')
                        plus = true;
                    if(plus && cur[j] != '@')
                        continue;
                    if(cur[j]=='.')
                        continue;
                }
                if(cur[j]=='@')
                    flag = false;
                
                s+=cur[j];
            }
            st.insert(s);
        }
        return st.size();
    }
};