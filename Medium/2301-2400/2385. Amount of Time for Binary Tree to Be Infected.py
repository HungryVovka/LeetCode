# 2385. Amount of Time for Binary Tree to Be Infected
# 
# You are given the root of a binary tree with unique values, and an integer start. At minute 0, an 
# infection starts from the node with value start.
# 
# Each minute, a node becomes infected if:
# 
# The node is currently uninfected.
# The node is adjacent to an infected node.
# 
# Return the number of minutes needed for the entire tree to be infected.
# 
# Example 1:
# Input: root = [1,5,3,null,4,10,6,9,2], start = 3
# Output: 4
# Explanation: The following nodes are infected during:
# - Minute 0: Node 3
# - Minute 1: Nodes 1, 10 and 6
# - Minute 2: Node 5
# - Minute 3: Node 4
# - Minute 4: Nodes 9 and 2
# It takes 4 minutes for the whole tree to be infected so we return 4.
# 
# Example 2:
# Input: root = [1], start = 1
# Output: 0
# Explanation: At minute 0, the only node in the tree is infected so we return 0.
#  
# Constraints:
# 
# The number of nodes in the tree is in the range [1, 10^5].
# 1 <= Node.val <= 10^5
# Each node has a unique value.
# A node with a value of start exists in the tree.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        def bfs(node):
            infected = set()
            queue = deque([(node, 0)])
            time = 0
            while queue:
                current_node, level = queue.popleft()
                infected.add(current_node.val)
                time = max(time, level)
                for neighbor in graph[current_node.val]:
                    if neighbor not in infected:
                        queue.append((TreeNode(neighbor), level + 1))
            return time
        
        graph = defaultdict(list)

        def build_graph(node):
            if node:
                if node.left:
                    graph[node.val].append(node.left.val)
                    graph[node.left.val].append(node.val)
                    build_graph(node.left)
                if node.right:
                    graph[node.val].append(node.right.val)
                    graph[node.right.val].append(node.val)
                    build_graph(node.right)
                    
        build_graph(root)
        return bfs(TreeNode(start))

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).