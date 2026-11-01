#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define debug(...) do { if(debug_on) { fprintf(stderr, __VA_ARGS__); } } while(0)

static int debug_on;

typedef struct{
    int x;
    int y;
} point;

int uniquePaths(int** grid, int gridSize, int* gridColSize) {
    int rowsize = gridSize, colsize = gridColSize[0];
    point go[rowsize][colsize][2]; // go right = 0, down = 1
    int dp[rowsize][colsize]; 

    // build go and initialize dp
    for(int i = rowsize-1; i >= 0; --i){
        for(int j = colsize-1; j >= 0; --j){
            dp[i][j] = 0;

            if(j+1 == colsize){
                go[i][j][0] = (point){.x = 0, .y = 0};
            } else if(grid[i][j+1]){
                go[i][j][0] = go[i][j+1][1];
            } else{
                go[i][j][0] = (point){.x = i, .y = j+1};
            }

            if(i+1 == rowsize){
                go[i][j][1] = (point){.x = 0, .y = 0};
            } else if(grid[i+1][j]){
                go[i][j][1] = go[i+1][j][0];
            } else{
                go[i][j][1] = (point){.x = i+1, .y = j};
            }
        }
    }

    dp[0][0] = 1;

    for(int i = 0; i < rowsize; ++i){
        for(int j = 0; j < colsize; ++j){
            if(dp[i][j] && !(i == rowsize-1 && j == colsize-1)){
                int x1 = go[i][j][0].x, y1 = go[i][j][0].y, x2 = go[i][j][1].x, y2 = go[i][j][1].y;

                debug("[debug] x1: %d, y1: %d, x2: %d, y2: %d, ", x1, y1, x2, y2);
                
                if(x1 || y1){
                    dp[x1][y1] = (dp[x1][y1] + dp[i][j]) % MOD;
                    debug("dp[%d][%d]: %d. ", x1, y1, dp[x1][y1]);
                } 

                if(x2 || y2){
                    dp[x2][y2] = (dp[x2][y2] + dp[i][j]) % MOD;
                    debug("dp[%d][%d]: %d. ", x2, y2, dp[x2][y2]);
                }

                debug("\n");
            }
        }
    }

    return dp[rowsize-1][colsize-1];
}

int main(int argc, char **argv){
    int rowsize, colInt;

    debug_on = getenv("DEBUG") != NULL;

    for(int i = 1; i < argc; ++i){
        if(!strcmp(argv[i], "-d") || !strcmp(argv[i], "--debug")){
            debug_on = 1;
            break;
        }
    }

    debug("row, col: ");
    scanf("%d%d", &rowsize, &colInt);

    int *colsize = (int *)malloc(rowsize * sizeof(int));
    
    for(int i = 0; i < rowsize; ++i) colsize[i] = colInt;
    
    int **grid = (int **)malloc(rowsize * sizeof(int *));
    
    debug("grid: %d x %d\n", rowsize, colInt);

    for(int i = 0; i < rowsize; ++i){
        grid[i] = (int*)malloc(colsize[i] * sizeof(int));

        for(int j = 0; j < colsize[i]; ++j){
            scanf("%d", &grid[i][j]);
        }
    }

    debug("Ans: %d\n", uniquePaths(grid, rowsize, colsize));

    free(colsize);
    for(int i = 0; i < rowsize; ++i) free(grid[i]);
    free(grid);

    return 0;
}