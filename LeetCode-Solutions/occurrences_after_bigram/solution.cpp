class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        stringstream ss(text);
        string word;
        vector<string> vec;
        while(ss>>word){
            vec.push_back(word);
        }
        for(int i = 0 ; i<vec.size()-2 ; i++){
            if(vec[i]==first && vec[i+1]==second){
                ans.push_back(vec[i+2]);
            }
        }
        return ans;
    }
};