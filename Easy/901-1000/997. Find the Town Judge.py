# 997. Find the Town Judge
# 
# In a town, there are n people labeled from 1 to n. There is a rumor that one of these 
# people is secretly the town judge.
# 
# If the town judge exists, then:
# 
# The town judge trusts nobody.
# Everybody (except for the town judge) trusts the town judge.
# There is exactly one person that satisfies properties 1 and 2.
# 
# You are given an array trust where trust[i] = [ai, bi] representing that the person 
# labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, 
# then such a trust relationship does not exist.
# 
# Return the label of the town judge if the town judge exists and can be identified, or return -1 
# otherwise.
# 
# Example 1:
# Input: n = 2, trust = [[1,2]]
# Output: 2
# 
# Example 2:
# Input: n = 3, trust = [[1,3],[2,3]]
# Output: 3
# 
# Example 3:
# Input: n = 3, trust = [[1,3],[2,3],[3,1]]
# Output: -1
# 
# Constraints:
# 
# 1 <= n <= 1000
# 0 <= trust.length <= 10^4
# trust[i].length == 2
# All the pairs of trust are unique.
# ai != bi
# 1 <= ai, bi <= n

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust_count = {}
        trusted_by = {}
        for a, b in trust:
            trust_count[b] = trust_count.get(b, 0) + 1
            trusted_by[a] = trusted_by.get(a, 0) + 1
        for i in range(1, n + 1):
            if trust_count.get(i, 0) == (n - 1) and trusted_by.get(i, 0) == 0:
                return i
        return -1

# or

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust_count = [0] * (n + 1)
        trusted_by = [0] * (n + 1)
        for a, b in trust:
            trust_count[b] += 1
            trusted_by[a] += 1
        for i in range(1, n + 1):
            if trust_count[i] == (n - 1) and trusted_by[i] == 0:
                return i
        return -1

# or

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust_count = [0] * (n + 1)
        for a, b in trust:
            trust_count[a] -= 1
            trust_count[b] += 1
        for i in range(1, n + 1):
            if trust_count[i] == (n - 1):
                return i
        return -1

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).