// 762. Prime Number of Set Bits in Binary Representation
//
// Given two integers left and right, return the count of numbers in the inclusive 
// range [left, right] having a prime number of set bits in their binary representation.
// 
// Recall that the number of set bits an integer has is the number of 1's present when 
// written in binary.
// 
// For example, 21 written in binary is 10101, which has 3 set bits.
//  
// 
// Example 1:
// 
// Input: left = 6, right = 10
// Output: 4
// Explanation:
// 6  -> 110 (2 set bits, 2 is prime)
// 7  -> 111 (3 set bits, 3 is prime)
// 8  -> 1000 (1 set bit, 1 is not prime)
// 9  -> 1001 (2 set bits, 2 is prime)
// 10 -> 1010 (2 set bits, 2 is prime)
// 4 numbers have a prime number of set bits.
// 
// Example 2:
// 
// Input: left = 10, right = 15
// Output: 5
// Explanation:
// 10 -> 1010 (2 set bits, 2 is prime)
// 11 -> 1011 (3 set bits, 3 is prime)
// 12 -> 1100 (2 set bits, 2 is prime)
// 13 -> 1101 (3 set bits, 3 is prime)
// 14 -> 1110 (3 set bits, 3 is prime)
// 15 -> 1111 (4 set bits, 4 is not prime)
// 5 numbers have a prime number of set bits.
//  
// 
// Constraints:
// 
// 1 <= left <= right <= 10^6
// 0 <= right - left <= 10^4

#include <stdbool.h>    // bool

static int countSetBits(int value){
    int count;
    count = 0;
    while (value != 0){
        value &= (value - 1);
        count++;
    }
    return count;
}

int countPrimeSetBits(int left, int right){
    bool isPrimeCount[21];
    int i;
    int answer;
    for (i = 0; i <= 20; ++i){
        isPrimeCount[i] = false;
    }
    isPrimeCount[2] = true;
    isPrimeCount[3] = true;
    isPrimeCount[5] = true;
    isPrimeCount[7] = true;
    isPrimeCount[11] = true;
    isPrimeCount[13] = true;
    isPrimeCount[17] = true;
    isPrimeCount[19] = true;
    answer = 0;
    for (i = left; i <= right; ++i){
        int bits;
        bits = countSetBits(i);
        if (isPrimeCount[bits]){
            answer++;
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