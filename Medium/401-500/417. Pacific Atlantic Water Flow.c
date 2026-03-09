// 417. Pacific Atlantic Water Flow
//
// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
// The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the 
// island's right and bottom edges.
// 
// The island is partitioned into a grid of square cells. You are given an m x n integer matrix 
// heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
// 
// The island receives a lot of rain, and the rain water can flow to neighboring cells directly 
// north, south, east, and west if the neighboring cell's height is less than or equal to 
// the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
// 
// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain 
// water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
// 
// Example 1:
// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean 
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean 
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean 
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// 
// Example 2:
// 
// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
//  
// 
// Constraints:
// 
// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 10^5

#include <stdlib.h>     // malloc, calloc

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int** heights, int m, int n, int r, int c, int** visited){
    visited[r][c] = 1;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int i;
    int nr, nc;
    for (i = 0; i < 4; i++){
        nr = r + dirs[i][0];
        nc = c + dirs[i][1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n){
            if (!visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]){
                    dfs(heights, m, n, nr, nc, visited);
                }
        }
    }
}

int** pacificAtlantic(int** heights, int heightsSize, 
int* heightsColSize, int* returnSize, int** returnColumnSizes){
    int m = heightsSize;
    int n = heightsColSize[0];
    int i, j;
    int** pacific;
    int** atlantic;
    int** answer;
    int capacity;
    pacific = (int**)malloc(m * sizeof(int*));
    atlantic = (int**)malloc(m * sizeof(int*));

    for (i = 0; i < m; i++){
        pacific[i] = (int*)calloc(n, sizeof(int));
        atlantic[i] = (int*)calloc(n, sizeof(int));
    }
    // Pacific's top and left borders
    for (i = 0; i < m; i++) dfs(heights, m, n, i, 0, pacific);
    for (j = 0; j < n; j++) dfs(heights, m, n, 0, j, pacific);
    // Atlantic's top and left borders
    for (i = 0; i < m; i++) dfs(heights, m, n, i, n - 1, atlantic);
    for (j = 0; j < n; j++) dfs(heights, m, n, m - 1, j, atlantic);
    capacity = m * n;
    answer = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (pacific[i][j] && atlantic[i][j]){
                answer[*returnSize] = (int*)malloc(2 * sizeof(int));
                answer[*returnSize][0] = i;
                answer[*returnSize][1] = j;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;

            }
        }
    }
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).