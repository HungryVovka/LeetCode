# 9. Palindrome Number
# Given an integer x, return true if x is a palindrome, and false otherwise.
# 
# Example 1:
# 
# Input: x = 121
# Output: true
# Explanation: 121 reads as 121 from left to right and from right to left.
# 
# Example 2:
# 
# Input: x = -121
# Output: false
# Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
# 
# Example 3:
# 
# Input: x = 10
# Output: false
# Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
# 
# Constraints:
# 
# -2^31 <= x <= 2^31 - 1
#  
# Follow up: Could you solve it without converting the integer to a string?

defmodule Solution do
  @spec is_palindrome(x :: integer) :: boolean
  def is_palindrome(x) when x < 0, do: false

  def is_palindrome(x) do
    original = x
    reversed = reverse_number(x, 0)
    original == reversed
  end

  defp reverse_number(0, acc), do: acc

  defp reverse_number(x, acc) do
    digit = rem(x, 10)
    reverse_number(div(x, 10), acc * 10 + digit)
  end
end

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).