from typing import List

class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        halfHight = k // 2
        for i in range(halfHight):
            for j in range(k):
                grid[x+i][y+j], grid[x+k-i-1][y+j] = grid[x+k-i-1][y+j], grid[x+i][y+j]
        return grid
