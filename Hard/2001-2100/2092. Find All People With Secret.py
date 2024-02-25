# 2092. Find All People With Secret
# 
# You are given an integer n indicating there are n people numbered from 0 to n - 1. You 
# are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, 
# timei] indicates that person xi and person yi have a meeting at timei. A person may 
# attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
# 
# Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. 
# This secret is then shared every time a meeting takes place with a person that has the secret. 
# More formally, for every meeting, if a person xi has the secret at timei, then they will share 
# the secret with person yi, and vice versa.
# 
# The secrets are shared instantaneously. That is, a person may receive the secret and share it 
# with people in other meetings within the same time frame.
# 
# Return a list of all the people that have the secret after all the meetings have taken place. You 
# may return the answer in any order.
# 
# Example 1:
# Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
# Output: [0,1,2,3,5]
# Explanation:
# At time 0, person 0 shares the secret with person 1.
# At time 5, person 1 shares the secret with person 2.
# At time 8, person 2 shares the secret with person 3.
# At time 10, person 1 shares the secret with person 5.
# Thus, people 0, 1, 2, 3, and 5 know the secret after all the 
# meetings.
# 
# Example 2:
# Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
# Output: [0,1,3]
# Explanation:
# At time 0, person 0 shares the secret with person 3.
# At time 2, neither person 1 nor person 2 know the secret.
# At time 3, person 3 shares the secret with person 0 and person 1.
# Thus, people 0, 1, and 3 know the secret after all the 
# meetings.
# 
# Example 3:
# Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
# Output: [0,1,2,3,4]
# Explanation:
# At time 0, person 0 shares the secret with person 1.
# At time 1, person 1 shares the secret with person 2, and person 2 
# shares the secret with person 3.
# Note that person 2 can share the secret at the same time as 
# receiving it.
# At time 2, person 3 shares the secret with person 4.
# Thus, people 0, 1, 2, 3, and 4 know the secret after all the 
# meetings.
# 
# Constraints:
# 
# 2 <= n <= 10^5
# 1 <= meetings.length <= 10^5
# meetings[i].length == 3
# 0 <= xi, yi <= n - 1
# xi != yi
# 1 <= timei <= 10^5
# 1 <= firstPerson <= n - 1

class Solution:
    def findAllPeople(self, \
    n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        people_with_secret = []
        connections = {}
        queue = [(0, 0), (0, firstPerson)]
        seen = set()
        for meeting in meetings:
            person1, person2, time = meeting
            if person1 not in connections:
                connections[person1] = []
            if person2 not in connections:
                connections[person2] = []
            connections[person1].append((person2, time))
            connections[person2].append((person1, time))
        heapq.heapify(queue)
        while queue:
            time, person = heapq.heappop(queue)
            if person not in seen:
                seen.add(person)
                people_with_secret.append(person)
                for neighbor, meeting_time in connections.get(person, []):
                    if meeting_time >= time and neighbor not in seen:
                        heapq.heappush(queue, (meeting_time, neighbor))
        return people_with_secret

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).