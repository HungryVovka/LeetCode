# 1235. Maximum Profit in Job Scheduling
# 
# We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of 
# profit[i].
# 
# You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are 
# no two jobs in the subset with overlapping time range.
# 
# If you choose a job that ends at time X you will be able to start another job that starts at time X.
# 
# Example 1:
# 
# Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
# Output: 120
# Explanation: The subset chosen is the first and fourth job. 
# Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
# 
# Example 2:
# 
# Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
# Output: 150
# Explanation: The subset chosen is the first, fourth and fifth job. 
# Profit obtained 150 = 20 + 70 + 60.
# 
# Example 3:
# 
# Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
# Output: 6
#  
# Constraints:
# 
# 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
# 1 <= startTime[i] < endTime[i] <= 10^9
# 1 <= profit[i] <= 10^4

class Solution:
    def jobScheduling(self,\
    startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = []
        i = 0
        while i < len(startTime):
            jobs.append((startTime[i], endTime[i], profit[i]))
            i += 1
        jobs.sort(key=lambda x: x[1])
        mp = [0] * len(jobs)
        mp[0] = jobs[0][2]

        def binary_search(jobs, start):
            low = 0
            high = start - 1
            while low <= high:
                mid = (low + high) // 2
                if jobs[mid][1] <= jobs[start][0]:
                    if jobs[mid+1][1] <= jobs[start][0]:
                        low = mid + 1
                    else:
                        return mid
                else:
                    high = mid - 1
            return -1
        
        j = 1
        while j < len(jobs):
            included_profit = jobs[j][2]
            prev_job_i = binary_search(jobs, j)
            if prev_job_i != -1:
                included_profit += mp[prev_job_i]
            mp[j] = max(included_profit, mp[j-1])
            j += 1
        return mp[-1]

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).