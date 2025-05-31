/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** triangle = malloc(sizeof(int*) * numRows);
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    *returnSize = numRows;
    for (int i = 0; i < numRows; i++) {
        triangle[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) triangle[i][j] = 1;
            else if(i > 1) triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]; 
        }
    }
    return triangle;
}