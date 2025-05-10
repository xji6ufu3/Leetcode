/**
 * Expand Around Center 中心擴展法
 * 把每一個字元都當作是中心，用一個迴圈檢查左右是否相同，若不相同或是觸及邊界就跳出迴圈
 * 記下最長的長度以及開頭，最後再回傳對應的子字串。
 * 最差的狀況是每一個字元都相同，每一次中心展開都要展開到邊界才會停下來，即 O (N^2)
 * 如果都不同，那就接近 O (N)。
 * 字串長度為奇數和偶數的狀況不同，所以要作兩次擴展
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 */

 int expandAroundCenter(char *s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  // (right - left + 1) - 2
}

char* longestPalindrome(char* s) {
    
    int len = strlen(s), start = 0, maxLen = 1;
    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int nowLen = (len1 > len2) ? len1 : len2;
        if (nowLen > maxLen) {
            maxLen = nowLen;
            start = i - (nowLen - 1) / 2;
        }
    }

    char *result = malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}