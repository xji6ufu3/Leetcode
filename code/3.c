int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;  // 初始化，每個字元的最後出現位置為 -1
    }

    int maxLength = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {  // 遍歷整個字串，直到遇到結尾的 '\0'
        char currentChar = s[right];

        // 如果當前字元已出現且在當前窗口中，移動 left 指標到重覆字符的下一個字元開始
        if (lastIndex[(int)currentChar] >= left) {
            left = lastIndex[(int)currentChar] + 1;
        }

        // 更新此字元的最後出現位置
        lastIndex[(int)currentChar] = right;

        // 計算當前窗口長度，並更新 maxLength
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}
