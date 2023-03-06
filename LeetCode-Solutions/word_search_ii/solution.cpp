class Solution {
public:
    const static int N = 4e5+6;
    int nxt[N][26],ok[N],nNodes = 0;
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        ok[nNodes] = 0;
        return nNodes++;
    }
    int root = 0;
    void init(){
        nNodes = 0;
        root = createNode();
    }
    
    void addString(string s){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'a'];
            if(child==-1)
                child = createNode();
            cur = child;
        }
        ok[cur] = 1;
    }
    
    int n,m;
    
    vector<int> Xs = {1,0,-1,0};
    vector<int> Ys = {0,1,0,-1};
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    string ans = "";
    vector<string> sol;
    int vis[14][14];
    void backtrack(vector<vector<char>>& board, int x, int y, int cur){
        int child = nxt[cur][board[x][y]-'a'];
        if(child==-1) return;
        if(ok[child]){
            sol.push_back(ans);
            ok[child] = 0;
        }
        for(int i = 0 ; i<4 ; i++){
            int newX = x+Xs[i];
            int newY = y+Ys[i];
            if(!valid(newX,newY) || vis[newX][newY]==1) continue;
            ans.push_back(board[newX][newY]);
            vis[newX][newY] = 1;
            backtrack(board,newX,newY,child);
            ans.pop_back();
            vis[newX][newY] = 0;
        }
    }

    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        init();
        for(int i = 0 ; i<words.size() ; i++){
            addString(words[i]);
        }
        n = board.size();
        m = board[0].size();
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                ans.push_back(board[i][j]);
                vis[i][j] = 1;
                backtrack(board,i,j,root);
                ans.pop_back();
                vis[i][j] = 0;
                
            }
        }
        return sol;
        
    }
};