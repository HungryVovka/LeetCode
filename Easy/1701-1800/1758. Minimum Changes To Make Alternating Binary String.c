// 1758. Minimum Changes To Make Alternating Binary String
//
// You are given a string s consisting only of the characters '0' and '1'. In one operation, 
// you can change any '0' to '1' or vice versa.
// 
// The string is called alternating if no two adjacent characters are equal. For example, 
// the string "010" is alternating, while the string "0100" is not.
// 
// Return the minimum number of operations needed to make s alternating.
// 
// 
// Example 1:
// 
// Input: s = "0100"
// Output: 1
// Explanation: If you change the last character to '1', s will be "0101", which is alternating.
// 
// Example 2:
// 
// Input: s = "10"
// Output: 0
// Explanation: s is already alternating.
// 
// Example 3:
// 
// Input: s = "1111"
// Output: 2
// Explanation: You need two operations to reach "0101" or "1010".
//  
// 
// Constraints:
// 
// 1 <= s.length <= 10^4
// s[i] is either '0' or '1'.

int minOperations(char* s){
    int i;
    int count0 = 0;
    int count1 = 0;
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] != ((i % 2 == 0) ? '0' : '1')) count0++;
        if (s[i] != ((i % 2 == 0) ? '1' : '0')) count1++;
    }
    return count0 < count1 ? count0 : count1;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).