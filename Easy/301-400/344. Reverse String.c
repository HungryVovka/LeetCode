// 344. Reverse String
//
// Write a function that reverses a string. The input string is given as an array 
// of characters s.
// 
// You must do this by modifying the input array in-place with O(1) extra memory.
// 
// 
// Example 1:
// 
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// 
// Example 2:
// 
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
//  
// 
// Constraints:
// 
// 1 <= s.length <= 10^5
// s[i] is a printable ascii character. 
// (https://en.wikipedia.org/wiki/ASCII#Printable_characters)

void reverseString(char* s, int sSize){
    int left_index;
    int right_index;
    char temp_char;
    if (s == NULL || sSize <= 1) return;
    left_index = 0;
    right_index = sSize - 1;
    while (left_index < right_index){
        temp_char = s[left_index];
        s[left_index] = s[right_index];
        s[right_index] = temp_char;
        left_index++;
        right_index--;
    }
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).