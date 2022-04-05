class Solution {
public:
    vector<string> board;
    bool isWin(char c){
        int wins = 0;
        for(int i = 0 ; i<3 ; i++){
            if(board[i][0] == c && board[i][0]==board[i][1] && board[i][0]==board[i][2]){
                return true;
            }
        }
        for(int i = 0 ; i<3 ; i++){
            if(board[0][i] == c && board[0][i]==board[1][i] && board[0][i]==board[2][i]){
                return true;
            }
        }
        
        if(board[0][0] == c && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            return true;
        }
        
        if(board[0][2] == c && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            return true;
        }
        return false;
        
        
    }
    bool validTicTacToe(vector<string>& board) {
        this->board = board;
        int Xs = 0;
        int Os = 0;
        for(int i = 0 ; i<3 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(board[i][j]=='X') Xs++;
                else if(board[i][j]=='O') Os++;
  
            }
        }
        if(! ((Xs-Os) == 0 || (Xs-Os)==1) ) return false;
        if(Xs==Os){
            return !isWin('X');
        }else{
            return !isWin('O');
        }
         return true;
    }
};