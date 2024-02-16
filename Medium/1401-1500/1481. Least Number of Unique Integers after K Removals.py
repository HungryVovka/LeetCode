# 1481. Least Number of Unique Integers after K Removals
# 
# Given an array of integers arr and an integer k. Find the least number of unique 
# integers after removing exactly k elements.
# 
# Example 1:
# Input: arr = [5,5,4], k = 1
# Output: 1
# Explanation: Remove the single 4, only 5 is left.
# 
# Example 2:
# Input: arr = [4,3,1,1,3,3,2], k = 3
# Output: 2
# Explanation: Remove 4, 2 and either one of the two 1s or three 
# 3s. 1 and 3 will be left.
# 
# Constraints:
# 
# 1 <= arr.length <= 10^5
# 1 <= arr[i] <= 10^9
# 0 <= k <= arr.length

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        unique = {}
        for i in arr:
            if i in unique:
                unique[i] += 1
            else:
                unique[i] = 1
        sorted_counts = sorted(unique.values())
        for j in sorted_counts:
            if k >= j:
                k -= j
                del unique[next(iter(unique.keys()))]
            else:
                break
        return len(unique)

# or

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        unique = {}
        for i in arr:
            if i in unique:
                unique[i] += 1
            else:
                unique[i] = 1
        sorted_counts = sorted(unique.values())
        for j in sorted_counts:
            if k >= j:
                k -= j
                del unique[next(iter(unique.keys()))]
            else:
                break
        return len(unique)

# or

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        unique = {}
        min_heap = []
        for i in arr:
            if i in unique:
                unique[i] += 1
            else:
                unique[i] = 1
        for frequency in unique.values():
            heapq.heappush(min_heap, frequency)
        while k > 0:
            k -= heapq.heappop(min_heap)
        return len(min_heap) + (1 if k < 0 else 0)

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).