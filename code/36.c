bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 9; i++) {
        bool check[9] = {false};
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            int num = board[i][j] - '1';
            if (num < 0 || num > 8 || check[num]) { 
                return false;
            }
            check[num] = true;
        }
    }

    for (int j = 0; j < 9; j++) {
        bool check[9] = {false};
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.') {
                continue;
            }
            int num = board[i][j] - '1';
            if (num < 0 || num > 8 || check[num]) {
                return false;
            }
            check[num] = true;
        }
    }

    for (int block = 0; block < 9; block++) {
        bool check[9] = {false}; 
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[startRow + i][startCol + j];
                if (c == '.') {
                    continue;
                }
                int num = c - '1';
                if (num < 0 || num > 8 || check[num]) {
                    return false;
                }
                check[num] = true;
            }
        }
    }

    return true;
}