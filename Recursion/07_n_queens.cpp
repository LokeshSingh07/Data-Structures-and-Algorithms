// 51. N-Queens

// Method 1
class Solution {
    public boolean isSafe(char board[][], int row, int col) {
        // vertical up
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        //diagonally up left-top
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        //diagonally up right-top
        for (int i = row - 1, j = col + 1; i >= 0 && j < board[0].length; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    public void nQueens(char board[][], int row) {
        if (row == board.length) {
            boardToList(board);
            return;
        }

        for (int j = 0; j < board[0].length; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1);
                board[row][j] = '.';
            }
        }
    }

    public void call(int n) {
        char board[][] = new char[n][n];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                board[i][j] = '.';
            }
        }

        nQueens(board, 0);
    }

    static ArrayList<List<String>> mainList = new ArrayList<>();
    public List<List<String>> boardToList(char[][] board) {
        ArrayList<String> list = new ArrayList<>();

        for (char[] row : board) {
            list.add(new String(row));
        }

        mainList.add(list);
        //System.out.println(list); // Output: [abc, def, ghi]
        return mainList;
    }

    public List<List<String>> solveNQueens(int n) {
        mainList.clear(); // ✅ Clear old results
        call(n);
        return mainList;   
    }
}