// Rat in a Maze Problem - I

class Solution {
    public:
    vector<string> result;
    int n;
    
    void solveRec(vector<vector<int>> &maze, int i, int j, string &temp){
        if(i<0 || i>=n || j<0 || j>=n || maze[i][j] == 0) return;
        if(i==n-1 && j==n-1){
            result.push_back(temp);
            return;
        }
        
        maze[i][j] = 0;
        
        // explore all 4 direction
        // Down
        temp.push_back('D');
        solveRec(maze, i+1, j, temp);
        temp.pop_back();
        
        // Left
        temp.push_back('L');
        solveRec(maze, i, j-1, temp);
        temp.pop_back();
        
        // Right
        temp.push_back('R');
        solveRec(maze, i, j+1, temp);
        temp.pop_back();
        
        // Up
        temp.push_back('U');
        solveRec(maze, i-1, j, temp);
        temp.pop_back();
        
        
        
        maze[i][j] = 1;
    }
    
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        int i=0, j=0;
        string temp = "";
        
        solveRec(maze, i, j, temp);
        
        return result;
    }
};