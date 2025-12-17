// 771. Jewels and Stones
// 
// You're given strings jewels representing the types of stones that are jewels, 
// and stones representing the stones you have. Each character in stones is 
// a type of stone you have. You want to know how many of the stones you have 
// are also jewels.
// 
// Letters are case sensitive, so "a" is considered a different type of stone from "A".
// 
// 
// Example 1:
// 
// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
// 
// Example 2:
// 
// Input: jewels = "z", stones = "ZZ"
// Output: 0
//  
// 
// Constraints:
// 
// 1 <= jewels.length, stones.length <= 50
// jewels and stones consist of only English letters.
// All the characters of jewels are unique.

#include <stddef.h>     // size_t

int numJewelsInStones(char* jewels, char* stones){
    int isJewel[128];
    int count;
    size_t i;
    unsigned char c;

    for (i = 0; i < 128; i++) isJewel[i] = 0;

    for (i = 0; jewels[i] != '\0'; i++){
        c = (unsigned char)jewels[i];
        isJewel[c] = 1;
    }

    count = 0;
    for (i = 0; stones[i] != '\0'; i++){
        c = (unsigned char)stones[i];
        if (isJewel[c]) count++;
    }
    return count;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).