/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* 卡塔蘭數 Catalan number 是一個常在計數問題中出現的數列
    * 例如：計算合法括號組合的數量，左括號要比右括號多。
    * 第 n 個卡塔蘭數 C(n) 可以用以下公式計算：
    * C(n) = (2n)! / ((n + 1)! * n!)
    * 或者使用遞迴公式：
    * C(0) = 1
    * C(n) = Σ C(i) * C(n - 1 - i) (i = 0 到 n - 1)
    * 證明：
    * 1. C(0) = 1，表示沒有括號時只有一種組合。 
    * 2. 對於 n > 0 的情況，考慮第一個括號必定是 '('，剩下的 n - 1 個括號可以分成兩部分：
    *   - 左邊的部分有 i 個 '('，右邊的部分有 n - 1 - i 個 ')'。
    *   - 左邊的部分可以有 C(i) 種組合，右邊的部分可以有 C(n - 1 - i) 種組合。
    */

void recursive(char **res, int *returnSize, char *tmpstr, int open, int close, int n){
    int pos = open + close;

    if (open == n && close == n) {
        tmpstr[pos] = '\0';
        res[*returnSize] = strdup(tmpstr);  // 複製一份結果
        (*returnSize)++;
        return;
    }

    if (open < n) {
        tmpstr[pos] = '(';
        recursive(res, returnSize, tmpstr, open + 1, close, n);
    }
    if (close < open) {
        tmpstr[pos] = ')';
        recursive(res, returnSize, tmpstr, open, close + 1, n);
    }
}
char** generateParenthesis(int n, int* returnSize) {

    int catalan[8+1] = {1, 1, 2, 5, 14, 42, 132, 429, 1430}; // 卡塔蘭數

    *returnSize = 0;
    
    char **res = malloc(sizeof(char *) * catalan[n]); // 儲存所有可能的字串
    char *tmpstr = malloc(sizeof(char) * (2 * n + 1)); // 組合字串

    recursive(res, returnSize, tmpstr, 0, 0, n);

    free(tmpstr);
    return res;
}