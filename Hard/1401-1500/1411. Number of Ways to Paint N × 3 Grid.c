// 1411. Number of Ways to Paint N × 3 Grid
//
// You have a grid of size n x 3 and you want to paint each cell of the grid with 
// exactly one of the three colors: Red, Yellow, or Green while making sure that 
// no two adjacent cells have the same color (i.e., no two cells that share vertical 
// or horizontal sides have the same color).
// 
// Given n the number of rows of the grid, return the number of ways you can paint this 
// grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.
// 
// Example 1:
// 
// +---+---+---+    +---+---+---+    +---+---+---+
// | R | Y | R |    | Y | R | Y |    | G | R | Y |
// +---+---+---+    +---+---+---+    +---+---+---+
// 
// +---+---+---+    +---+---+---+    +---+---+---+
// | R | Y | G |    | Y | R | G |    | G | R | G |
// +---+---+---+    +---+---+---+    +---+---+---+
// 
// +---+---+---+    +---+---+---+    +---+---+---+
// | R | G | R |    | Y | G | R |    | G | Y | R |
// +---+---+---+    +---+---+---+    +---+---+---+
// 
// +---+---+---+    +---+---+---+    +---+---+---+
// | R | G | Y |    | Y | G | Y |    | G | Y | G |
// +---+---+---+    +---+---+---+    +---+---+---+
// 
// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown.
// 
// Example 2:
// 
// Input: n = 5000
// Output: 30228214
//  
// 
// Constraints:
// 
// n == grid.length
// 1 <= n <= 5000

#include <stddef.h>     // size_t

int numOfWays(int n){
    const long long MOD = 1000000007LL;
    long long aba;
    long long abc;
    long long i;
    aba = 6;
    abc = 6;
    for (i = 2; i <= (long long)n; i++){
        long long abaNext;
        long long abcNext;
        abaNext = (3LL * aba + 2LL * abc) % MOD;
        abcNext = (2LL * aba + 2LL * abc) % MOD;
        aba = abaNext;
        abc = abcNext;
    }
    return (int)((aba + abc) % MOD);
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).