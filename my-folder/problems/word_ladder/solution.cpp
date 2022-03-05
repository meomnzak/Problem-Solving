class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> mp;
        for(auto elem : wordList){
            mp[elem] = 1;
        }
        return bfs(beginWord,endWord,mp);
    }
    
    
    int bfs(string beginWord, string endWord, map<string,int> mp){
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
                       level++;
            while(sz--){
                string u = q.front();
                if(u==endWord) return level;
                q.pop();
                for(int i = 0 ; i<u.size() ; i++){
                    for(int j = 0 ; j<26 ; j++){
                        char ch = (char)('a'+j);
                        string temp = u;
                        temp[i] = ch;
                        if(mp.find(temp)!=mp.end()){
                            q.push(temp);
                            mp.erase(temp);
                        }
                    }
                }
            }
 
        }
        return 0;
    }
};