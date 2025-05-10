const char* keypad[] = {
    "",
    "", 
    "abc", 
    "def",
    "ghi",
    "jkl", 
    "mno", 
    "pqrs",
    "tuv", 
    "wxyz" 
};

char** createStringArray(int size) {
    char** arr = malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(5 * sizeof(char));
    }
    return arr;
}

void backtrack(char* digits, int index, char* current, char** result, int* returnSize) {
    if (index == strlen(digits)) {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    const char* letters = keypad[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) {
        return NULL;
    }

    int maxCombinations = 1;
    for (int i = 0; i < len; i++) {
        maxCombinations *= strlen(keypad[digits[i] - '0']);
    }

    char** result = createStringArray(maxCombinations);
    char* current = (char*)malloc((len + 1) * sizeof(char));
    current[len] = '\0';

    backtrack(digits, 0, current, result, returnSize);
    free(current);

    return result;
}