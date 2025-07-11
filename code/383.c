bool canConstruct(char* ransomNote, char* magazine) {
    int count[26] = {0};
    while (*magazine) count[*(magazine++) - 'a']++;
    while (*ransomNote) {
        if (--count[*(ransomNote++) - 'a'] < 0) return false;
    }
    return true;
}
