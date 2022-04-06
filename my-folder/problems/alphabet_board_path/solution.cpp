class Solution {
public:
    
    
    string path = "";
    
    void LR(int xDiff){
            if(xDiff < 0){
                for(int i = 0 ; i<abs(xDiff) ; i++){
                    path+='R';
                }
            }else{
                for(int i = 0 ; i<abs(xDiff) ; i++){
                    path+='L';
                }
            }
    }
    
    void UD(int yDiff){
        if(yDiff < 0){
                for(int i = 0 ; i<abs(yDiff) ; i++){
                    path+='D';
                }
            }else{
                for(int i = 0 ; i<abs(yDiff) ; i++){
                    path+='U';
                }
            }
    }
    
    string alphabetBoardPath(string target) {
        map<char,pair<int,int>> mp;
        char ch = 'a';
        for(int i = 0 ; i<5; i++){
            for(int j = 0 ; j<5 ; j++){
                mp[ch] = {i,j};
                ch = (char)(ch+1);
            }
        }
        mp['z'] = {5,0};
        
        char cur = 'a';
        char nxt;
        for(int i = 0 ; i<target.size() ; i++){
            nxt = target[i];
            int xDiff = mp[cur].second - mp[nxt].second;
            int yDiff = mp[cur].first - mp[nxt].first;
            if(cur=='z'){
                UD(yDiff);
                LR(xDiff);
            }else{
                 LR(xDiff);
                UD(yDiff);
            }
            
            path+='!';
            
            cur = nxt;
        }
        return path;
    }
};