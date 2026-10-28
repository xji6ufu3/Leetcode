void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    
    // transpose the matrix along the diagonal

    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < i; ++j){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    // reverse each row horizontally
    
    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < matrixSize/2; ++j){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = tmp;
        }
    }
}
