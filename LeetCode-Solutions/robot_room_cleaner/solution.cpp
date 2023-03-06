/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<int> Xs = {1,0,-1,0};
    vector<int> Ys = {0,1,0,-1};
    vector<char> Dir = {'R','D','L','U'};
    vector<char> Inv = {'L','U','R','D'};
    void to(Robot& robot,char where, char cur){
        if(where=='U' && cur=='L'){
            robot.turnRight();
        }else if(where=='U' && cur=='R'){
            robot.turnLeft();
        }else if(where=='U' && cur=='D'){
            robot.turnRight();
            robot.turnRight();
        }else if(where=='D' && cur=='L'){
            robot.turnLeft();
        }else if(where=='D' && cur=='R'){
             robot.turnRight();
        }else if(where=='D' && cur=='U'){
            robot.turnRight();
            robot.turnRight();
        }else if(where=='R' && cur=='L'){
            robot.turnRight();
            robot.turnRight();
        }else if(where=='R' && cur=='U'){
            robot.turnRight();
        }else if(where=='R' && cur=='D'){
            robot.turnLeft();
        }else if(where=='L' && cur=='R'){
            robot.turnRight();
            robot.turnRight();
        }else if(where=='L' && cur=='U'){
            robot.turnLeft();
        }else if(where=='L' && cur=='D'){
            robot.turnRight();
        }
    }
    
    const static int N = 406;
    const static int M = 206;
    int vis[N][M];
    bool valid(int x, int y){
        return x>=0&&x<N&&y>=0&&y<M;
    }
    void dfs(Robot& robot,int x, int y, char dir){
        vis[x][y] = 1;
        robot.clean();
        for(int i = 0 ; i<4 ; i++){
            int newX = x+Xs[i];
            int newY = y+Ys[i];
            char newDir = Dir[i];
            to(robot,newDir,dir);
            if(valid(newX,newY) && !vis[newX][newY] && robot.move()){
                dfs(robot,newX,newY,newDir);
                char inverso = Inv[i];
                to(robot,inverso,newDir);
                robot.move();
                to(robot,dir,inverso);
            }else{
                to(robot,dir,newDir);
            }
            
        }
    }
    
    void cleanRoom(Robot& robot) {
        dfs(robot,202,102,'U');
    }
};