# 2709. Greatest Common Divisor Traversal
# 
# You are given a 0-indexed integer array nums, and you are allowed to traverse between its 
# indices. You can traverse between index i and index j, i != j, if and only if 
# gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.
# 
# Your task is to determine if for every pair of indices i and j in nums, where i < j, there 
# exists a sequence of traversals that can take us from i to j.
# 
# Return true if it is possible to traverse between all such pairs of indices, or false otherwise.
# 
# Example 1:
# 
# Input: nums = [2,3,6]
# Output: true
# Explanation: In this example, there are 3 possible pairs of 
# indices: (0, 1), (0, 2), and (1, 2).
# To go from index 0 to index 1, we can use the sequence of 
# traversals 0 -> 2 -> 1, where we move from index 0 to index 2 
# because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move 
# from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) 
# = 3 > 1.
# To go from index 0 to index 2, we can just go directly because 
# gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from 
# index 1 to index 2, we can just go directly because gcd(nums[1], 
# nums[2]) = gcd(3, 6) = 3 > 1.
# 
# Example 2:
# Input: nums = [3,9,5]
# Output: false
# Explanation: No sequence of traversals can take us from index 0 
# to index 2 in this example. So, we return false.
# 
# Example 3:
# Input: nums = [4,3,12,8]
# Output: true
# Explanation: There are 6 possible pairs of indices to traverse 
# between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A 
# valid sequence of traversals exists for each pair, so we return 
# true.
# 
# Constraints:
# 
# 1 <= nums.length <= 10^5
# 1 <= nums[i] <= 10^5

class Solution:
    def gcd(self, a: int, b: int) -> int:
        while b:
            a, b = b, a % b
        return a

    def get_prime_divisors(self, num: int) -> Set[int]:
        if num < 0:
            return set()
        factors = set()
        for i in range(2, int(num ** 0.5) + 1):
            while num % i == 0:
                factors.add(i)
                num //= i
        if num > 1:
            factors.add(num)
        return factors

    def find(self, parent: List[int], i: int) -> int:
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def union(self, \
    parent: List[int], rank: List[int], x: int, y: int) -> None:
        x_root = self.find(parent, x)
        y_root = self.find(parent, y)
        if x_root != y_root:
            if rank[x_root] < rank[y_root]:
                parent[x_root] = y_root
            elif rank[x_root] > rank[y_root]:
                parent[y_root] = x_root
            else:
                parent[y_root] = x_root
                rank[x_root] += 1

    def canTraverseAllPairs(self, numbers: List[int]) -> bool:
        n = len(numbers)
        parent = [i for i in range(n)]
        rank = [0] * n
        primes_dict = defaultdict(list)
        for idx, num in enumerate(numbers):
            prime_divisors = self.get_prime_divisors(num)
            for divisor in prime_divisors:
                primes_dict[divisor].append(idx)
        for divisor in primes_dict:
            group_root = primes_dict[divisor][0]
            for idx in primes_dict[divisor][1:]:
                self.union(parent, rank, group_root, idx)
        root = self.find(parent, 0)
        return all(self.find(parent, i) == root for i in range(n))

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).