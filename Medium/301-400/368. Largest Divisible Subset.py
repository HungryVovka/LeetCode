# 368. Largest Divisible Subset
# 
# Given a set of distinct positive integers nums, return the largest subset answer such that 
# every pair (answer[i], answer[j]) of elements in this subset satisfies:
# 
# answer[i] % answer[j] == 0, or
# answer[j] % answer[i] == 0
# 
# If there are multiple solutions, return any of them.
# 
# Example 1:
# Input: nums = [1,2,3]
# Output: [1,2]
# Explanation: [1,3] is also accepted.
# 
# Example 2:
# Input: nums = [1,2,4,8]
# Output: [1,2,4,8]
# 
# Constraints:
# 
# 1 <= nums.length <= 1000
# 1 <= nums[i] <= 2 * 10^9
# All the integers in nums are unique.

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        answer = []
        n = len(nums)
        count, prev_index = {}, {}
        max_count = 0
        index = -1
        nums.sort()
        self.calculate_counts(nums, count, prev_index)
        index = self.find_max_count_index(nums, count, max_count)
        self.construct_answer(nums, prev_index, index, answer)
        return answer

    def calculate_counts(self, nums: List[int], \
    count: dict, prev_index: dict) -> None:
        for a, b in enumerate(nums):
            count[b] = 1
            prev_index[b] = -1
            for c in reversed(range(a)):
                if b % nums[c] == 0 and count[b] < count[nums[c]] + 1:
                    count[b] = count[nums[c]] + 1
                    prev_index[b] = c

    def find_max_count_index(self, nums: List[int], \
    count: dict, max_count: int) -> int:
        index = -1
        for a, b in enumerate(nums):
            if count[b] > max_count:
                max_count = count[b]
                index = a
        return index

    def construct_answer(self, nums: List[int], \
    prev_index: dict, index: int, answer: List[int]) -> None:
        while index != -1:
            answer.append(nums[index])
            index = prev_index[nums[index]]

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).