void reverseString(char* s, int sSize) {
    int left = 0, right = sSize-1;
    while(left < right){
        char c = s[left];
        s[left] = s[right];
        s[right] = c;
        left++;
        right--;
    }
}