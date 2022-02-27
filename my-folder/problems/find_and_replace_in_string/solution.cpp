class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,pair<string,string>>> vec;
        for(int i = 0 ; i<indices.size() ; i++){
            vec.push_back({indices[i],{sources[i],targets[i]}});
        }
        sort(vec.begin(),vec.end());
        unordered_map<int,int> mp;
        for(int i = 0 ; i<vec.size() ; i++){
            if(s.substr(vec[i].first,vec[i].second.first.size())==vec[i].second.first){
                mp[vec[i].first] = i;
            }
        }
        string sol = "";
        for(int i = 0 ; i<s.size() ;){
            if(mp.find(i)!=mp.end()){
                sol+=vec[mp[i]].second.second;
                i+=vec[mp[i]].second.first.size();
            }else{
                sol+=s[i];
                i++;
            }
        }
        return sol;
    }
};