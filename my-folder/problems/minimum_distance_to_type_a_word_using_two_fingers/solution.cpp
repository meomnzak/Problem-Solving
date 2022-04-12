class Solution {
public:
    

    map<int,pair<int,int>> mp;
    
    const static int N = 304;
    
    int meme[304][27][27];
    
    string word;
    
    int solve(int idx, int finger1, int finger2){
        if(idx==word.size()) return 0;
        int &ret = meme[idx][finger1][finger2];
        if(~ret) return ret;
        auto p = mp[(word[idx]-'A')+1];
        auto f1 = mp[finger1];
        auto f2 = mp[finger2];
        int val1 = (finger1==0) ? 0 : (abs(f1.first-p.first)+abs(f1.second-p.second));
        int val2 = (finger2==0) ? 0 : (abs(f2.first-p.first)+abs(f2.second-p.second));
        int newPos = (word[idx]-'A')+1; 
        ret = min(solve(idx+1,newPos,finger2)+val1, solve(idx+1,finger1,newPos)+val2);
        return ret;
    }
        
    int minimumDistance(string word) {
        this->word = word;
        memset(meme,-1,sizeof(meme));
        int id = 1;
        for(int i = 0 ; i<5 ; i++){
            for(int j = 0 ; j<6 ; j++){
                mp[id] = {i,j};
                id++;
                if(id==27) break;
            }
        }
        return solve(0,0,0);
        
    }
};