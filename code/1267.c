int countServers(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0], cnt = 0;
    int colrow[n + 1];

    for(int i = 0; i < n + 1; ++i){
        colrow[i] = 0;
    }

    for(int i = 0; i < m; ++i){
        int rowcol = 0;

        for(int j = 0; j < n; ++j){
            if(grid[i][j]){
                if(rowcol || colrow[j + 1]){
                    ++cnt;

                    if(!rowcol){
                        rowcol = (j + 1) * -1;
                    } else if(!colrow[j + 1]){
                        colrow[j + 1] = (i + 1) * -1;
                    }

                    if(rowcol > 0){
                        ++cnt;
                        if(colrow[rowcol] > 0) colrow[rowcol] *= -1;
                        rowcol *= -1;
                    }
                    
                    if(colrow[j + 1] > 0){
                        ++cnt;
                        colrow[j + 1] *= -1;
                    }
                } else{
                    rowcol = j + 1;
                    colrow[j + 1] = i + 1;
                }
            }
        }
    }

    return cnt;
}
