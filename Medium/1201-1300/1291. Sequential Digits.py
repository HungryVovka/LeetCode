# 1291. Sequential Digits
# 
# An integer has sequential digits if and only if each digit in the number is one more than the 
# previous digit.
# 
# Return a sorted list of all the integers in the range [low, high] inclusive that have 
# sequential digits.
# 
# Example 1:
# Input: low = 100, high = 300
# Output: [123,234]
# 
# Example 2:
# Input: low = 1000, high = 13000
# Output: [1234,2345,3456,4567,5678,6789,12345]
# 
# Constraints:
# 
# 10 <= low <= high <= 10^9

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        answer = []
        all_digits = "123456789"
        for i in range(len(all_digits)):
            for j in range(i+1, len(all_digits)):
                num = int(all_digits[i:j+1])
                if low <= num <= high:
                    answer.append(num)
                elif num > high:
                    break
        return sorted(answer)

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).