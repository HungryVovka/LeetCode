// 345. Reverse Vowels of a String
//
// Given a string s, reverse only all the vowels in the string and return it.
// 
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower 
// and upper cases, more than once.
// 
// 
// Example 1:
// 
// Input: s = "IceCreAm"
// 
// Output: "AceCreIm"
// 
// Explanation:
// 
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
// 
// Example 2:
// 
// Input: s = "leetcode"
// 
// Output: "leotcede"
//  
// 
// Constraints:
// 
// 1 <= s.length <= 3 * 10^5
// s consist of printable ASCII characters.

static int is_vowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

char* reverseVowels(char* s) {
    int left_index;
    int right_index;
    char temp_char;
    if (s == NULL) return s;
    right_index = 0;
    while (s[right_index] != '\0') right_index++;
    right_index--;
    left_index = 0;
    while (left_index < right_index){
        while (left_index < right_index && !is_vowel(s[left_index])){
            left_index++;
        }
        while (left_index < right_index && !is_vowel(s[right_index])){
            right_index--;
        }
        if (left_index < right_index){
            temp_char = s[left_index];
            s[left_index] = s[right_index];
            s[right_index] = temp_char;
            left_index++;
            right_index--;
        }
    }
    return s;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).