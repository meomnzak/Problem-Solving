class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        char lst = s[0];
        int cnt = 1;
        vector<pair<char,int>> vec;
        for(int i = 1 ; i<s.size() ; i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                vec.push_back({lst,cnt});
                cnt = 1;
                lst = s[i];
            }
        }
        vec.push_back({lst,cnt});
        
        vector<vector<pair<char,int>>> all;
        for(int i = 0 ; i<words.size() ; i++){
            char lst = words[i][0];
            int cnt = 1;
            vector<pair<char,int>> cur;
            for(int j = 1 ; j<words[i].size() ; j++){
                if(words[i][j]==words[i][j-1]){
                    cnt++;
                }else{
                    cur.push_back({lst,cnt});
                    cnt = 1;
                    lst = words[i][j];
                }
            }
            cur.push_back({lst,cnt});
            all.push_back(cur);
        }
        int ans = 0;
        for(int i = 0 ; i<all.size() ; i++){
            if(all[i].size()!=vec.size()){
                continue;
            }else{
                bool flag= true;
                for(int j = 0 ; j<vec.size() ; j++){
                    if(vec[j].first != all[i][j].first){
                        flag = false;
                        break;
                    }else if(vec[j].second<all[i][j].second){
                        flag = false;
                        break;
                    }else if((vec[j].second != all[i][j].second) && vec[j].second<=2){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};