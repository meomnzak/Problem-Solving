class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;
        int n = sentence1.size();
        unordered_map<string,vector<string>> mp;
        for(int i = 0 ; i<similarPairs.size() ; i++){
            mp[similarPairs[i][0]].push_back(similarPairs[i][1]);
            mp[similarPairs[i][1]].push_back(similarPairs[i][0]);
        }
        for(int i = 0 ; i<n ; i++){
            bool flag = false;
            vector<string> vec = mp[sentence1[i]];
            for(int j = 0 ; j<vec.size() ; j++){
                if(vec[j]==sentence2[i]){
                    flag = true;
                    break;
                }
            }
            if( !(flag || sentence1[i]==sentence2[i]) ) return false;
        }
        return true;
    }
};