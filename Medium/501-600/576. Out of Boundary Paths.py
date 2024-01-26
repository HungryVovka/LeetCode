# 576. Out of Boundary Paths
# 
# There is an m x n grid with a ball. The ball is initially at the position [startRow, 
# startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (
# possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves 
# to the ball.
# 
# Given the five integers m, n, maxMove, startRow, startColumn, return the number of 
# paths to move the ball out of the grid boundary. Since the answer can be very large, return it 
# modulo 10^9 + 7.
# 
# Example 1:
# Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
# Output: 6
# 
# Example 2:
# Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
# Output: 12
# 
# Constraints:
# 
# 1 <= m, n <= 50
# 0 <= maxMove <= 50
# 0 <= startRow < m
# 0 <= startColumn < n

class Solution:
    def __init__(self):
        self.mod: int = int(1e9 + 7)
        self.memo: dict = {}
        self.m = 0
        self.n = 0

    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        self.m = m
        self.n = n
        return self.dp(maxMove, startRow, startColumn)

    def dp(self, maxMove: int, row: int, col: int) -> int:
        if (maxMove, row, col) in self.memo:
            return self.memo[(maxMove, row, col)]
        if row < 0 or row == self.m or col < 0 or col == self.n:
            return 1
        if maxMove == 0:
            return 0
        out_grid = (self.dp(maxMove - 1, row + 1, col) + self.dp(maxMove - 1, row - 1, col) +
                    self.dp(maxMove - 1, row, col + 1) + self.dp(maxMove - 1, row, col - 1)) % self.mod
        self.memo[(maxMove, row, col)] = out_grid
        return out_grid

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).