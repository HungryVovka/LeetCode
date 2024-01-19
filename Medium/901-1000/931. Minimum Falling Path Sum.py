# 931. Minimum Falling Path Sum
# 
# Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
# 
# A falling path starts at any element in the first row and chooses the element in the next row that is either 
# directly below or diagonally left/right. Specifically, the next element from position (row, col) will be 
# (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
# 
# Example 1:
# Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
# Output: 13
# Explanation: There are two falling paths with a minimum sum as shown.
# 
# Example 2:
# Input: matrix = [[-19,57],[-40,-5]]
# Output: -59
# Explanation: The falling path with a minimum sum is shown.
# 
# Constraints:
# 
# n == matrix.length == matrix[i].length
# 1 <= n <= 100
# -100 <= matrix[i][j] <= 100

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        new_matrix = self.fill_matrix(matrix, n)
        return min(new_matrix[-1])

    def fill_matrix(self, matrix: List[List[int]], n: int) -> List[List[int]]:
        new_matrix = list(map(lambda x: [0] * n, range(n)))
        i = 0
        while i < n:
            new_matrix[0][i] = matrix[0][i]
            i += 1
        a = 1
        while a < n:
            b = 0
            while b < n:
                min_path = new_matrix[a-1][b]
                if b > 0:
                    min_path = min(min_path, new_matrix[a-1][b-1])
                if b < n-1:
                    min_path = min(min_path, new_matrix[a-1][b+1])
                new_matrix[a][b] = min_path + matrix[a][b]
                b += 1
            a += 1
        return new_matrix

# or

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        new_matrix = list(self.fill_matrix(matrix, n))
        return min(new_matrix[-1])

    def fill_matrix(self, matrix: List[List[int]], n: int) -> List[List[int]]:
        def make_new_row(prev_row, curr_row):
            i = 0
            while i < n:
                min_path = prev_row[i]
                if i > 0:
                    min_path = min(min_path, prev_row[i-1])
                if i < n-1:
                    min_path = min(min_path, prev_row[i+1])
                yield min_path + curr_row[i]
                i += 1
        
        new_row = matrix[0]
        yield new_row
        a = 1
        while a < n:
            new_row = list(make_new_row(new_row, matrix[a]))
            yield new_row
            a += 1

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).