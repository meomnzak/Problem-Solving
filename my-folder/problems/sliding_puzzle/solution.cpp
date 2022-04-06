class Solution {
public:
    
    bool isRight(vector<vector<int>> vec){
        vector<vector<int>> finale = {{1,2,3},{4,5,0}};
        return finale==vec;
    }
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,-1,1};
    
    vector<vector<int>> board;
    
    bool isValid(int x, int y){
        return x>=0&&x<2&&y>=0&&y<3;
    }
    
    
    struct state{
        int x, y;
        vector<vector<int>> puzzle;
        state(int x, int y, vector<vector<int>> puzzle){
            this->x = x;
            this->y = y;
            this->puzzle = puzzle;
        }
    };
    
    map<vector<vector<int>>,bool> vis;
    
    int bfs(int srcX, int srcY){
        queue<state> q;
        q.push({srcX,srcY,board});
        vis[board] = 1;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                state u = q.front();
                if(isRight(u.puzzle)) return lvl; 
                q.pop();
                for(int i = 0 ; i<4 ; i++){
                    int newX = u.x+Xs[i];
                    int newY = u.y+Ys[i];
                    if(!isValid(newX,newY)) continue;
                    vector<vector<int>> newBoard = u.puzzle;
                    swap(newBoard[u.x][u.y],newBoard[newX][newY]);
                    if(vis[newBoard]) continue;
                    vis[newBoard] = 1;
                    q.push(state(newX,newY,newBoard));
                }
            }
            lvl++;
        }
        return -1;
    }
    
 
    
    int slidingPuzzle(vector<vector<int>>& board) {
        this->board = board;
        int x = 0 ,y = 0;
        for(int i = 0 ; i<board.size() ; i++){
            for(int j = 0 ; j<board[0].size() ; j++){
                if(board[i][j]==0){
                    x = i;
                    y = j;
                }
            }
        }
        return bfs(x,y);
        
    }
};