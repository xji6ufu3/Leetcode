/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* ret = malloc(sizeof(int) * (digitsSize + 1));
    int plus = 1;
    for(int i = digitsSize; i >= 1; i--){
        ret[i] = (digits[i-1] + plus) % 10;
        plus = (digits[i-1] + plus) / 10;
    }
    ret[0] = plus;
    *returnSize = ret[0] ? digitsSize + 1 : digitsSize;
    return ret[0] ? ret : &ret[1];
}