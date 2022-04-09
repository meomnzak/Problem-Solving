class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        int n = moves.size();
        for(int i = 0 ; i<n ; i++){
            if(moves[i]=='U') y++;
            else if(moves[i]=='D') y--;
            else if(moves[i]=='R') x++;
            else x--;
        }
        return (x==0&&y==0);
    }
};