/* 以下方式 Time Complexity: O(n) */

/*
char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1) {
        char* result = malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    char* rows[numRows];
    for (int i = 0; i < numRows; i++) {
        rows[i] = calloc(len + 1, sizeof(char));
    }

    int nowRow = 0;
    int direction = 1;  // 1 表示向下，-1 表示向上

    for (int i = 0; i < len; i++) {
        int rowLen = strlen(rows[nowRow]);
        rows[nowRow][rowLen] = s[i];
        rows[nowRow][rowLen + 1] = '\0';

        if (nowRow == 0) {
            direction = 1;
        } else if (nowRow == numRows - 1) {
            direction = -1;
        }

        nowRow += direction;
    }

    char* result = malloc((len + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }

    return result;
}
*/

/* 以下方式 Time Complexity: O(1) */

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    // 計算每個 Z 字形週期的長度
    int cycleLen = 2 * numRows - 2;

    char* result = malloc((len + 1) * sizeof(char));
    int index = 0;

    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < len; j += cycleLen) {
            // 垂直列字符：直接加入結果
            result[index++] = s[j];

            /**
             * 斜向列字符：
             * - 排除第一行 (row == 0) 和最後一行 (row == numRows - 1)
             * - diagIndex 計算方式：j + cycleLen - 2 * row
             */

            int diagIndex = j + cycleLen - 2 * row;
            if (row != 0 && row != numRows - 1 && diagIndex < len) {
                result[index++] = s[diagIndex];
            }
        }
    }

    result[index] = '\0';
    return result;
}