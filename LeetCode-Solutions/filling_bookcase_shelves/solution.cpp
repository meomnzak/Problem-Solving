class Solution {
public:
    
    const static int N = 1e3+6;
    
    int meme[N];
    
    vector<vector<int>> books;
    int shelfWidth;
    
    int n;
    
    int solve(int idx){
        if(idx==n) return 0;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 1e9;
        int curWidth = 0;
        int maxHigh = 0;
        for(int i = idx; i<n ; i++){
            if(books[i][0]+curWidth<=shelfWidth){
                curWidth+=books[i][0];
                maxHigh = max(maxHigh,books[i][1]);
                ret = min(ret,solve(i+1)+maxHigh);
            }else{
                break;
            }
        }
        return ret;
    }
    
    
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        this->books = books;
        this->shelfWidth = shelfWidth;
        memset(meme,-1,sizeof(meme));
        return solve(0);
    }
};