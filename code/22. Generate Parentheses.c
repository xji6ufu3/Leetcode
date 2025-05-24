/**
 * Note: The returned array must be malloced, assume caller calls free().
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