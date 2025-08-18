// 79. Word Search

class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0}, {-1,0},{0,-1}};
    int m, n, l;
    bool DFS(vector<vector<char>>& board, int i, int j, string &word, int k, vector<vector<bool>> &visited){
        if(k == l) return true;

        visited[i][j] = true;

        for(auto &dir: dirs){
            int newX = i + dir[0];
            int newY = j + dir[1];

            if(newX>=0 && newX<m && newY>=0 && newY<n && board[newX][newY] == word[k] && !visited[newX][newY]){
                bool ans = DFS(board, newX, newY, word, k+1, visited);
                if(ans) return true;
            }
        }


        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0] && DFS(board, i, j, word, 1, visited)) return true; 
            }
        }
        return false;
    }
};