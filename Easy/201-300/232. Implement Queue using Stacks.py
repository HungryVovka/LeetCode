# 232. Implement Queue using Stacks
# 
# Implement a first in first out (FIFO) queue using only two stacks. The implemented queue 
# should support all the functions of a normal queue (push, peek, pop, and empty).
# 
# Implement the MyQueue class:
# 
# void push(int x) Pushes element x to the back of the queue.
# int pop() Removes the element from the front of the queue and returns it.
# int peek() Returns the element at the front of the queue.
# boolean empty() Returns true if the queue is empty, false otherwise.
# Notes:
# 
# You must use only standard operations of a stack, which means only push to top, 
# peek/pop from top, size, and is empty operations are valid.
# Depending on your language, the stack may not be supported natively. You may 
# simulate a stack using a list or deque (double-ended queue) as long as you use only a 
# stack's standard operations.
# 
# Example 1:
# Input
# ["MyQueue", "push", "push", "peek", "pop", "empty"]
# [[], [1], [2], [], [], []]
# Output
# [null, null, null, 1, 1, false]
# 
# Explanation
# MyQueue myQueue = new MyQueue();
# myQueue.push(1); // queue is: [1]
# myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
# myQueue.peek(); // return 1
# myQueue.pop(); // return 1, queue is [2]
# myQueue.empty(); // return false
# 
# Constraints:
# 
# 1 <= x <= 9
# At most 100 calls will be made to push, pop, peek, and empty.
# All the calls to pop and peek are valid.

class MyQueue:
    def __init__(self):
        self.arr1 = []
        self.arr2 = []

    def push(self, x: int) -> None:
        self.arr1.append(x)

    def _transfer_elements(self):
        if not self.arr2:
            while self.arr1:
                self.arr2.append(self.arr1.pop())

    def pop(self) -> int:
        self._transfer_elements()
        return self.arr2.pop()

    def peek(self) -> int:
        self._transfer_elements()
        return self.arr2[-1]

    def empty(self) -> bool:
        return not (self.arr1 or self.arr2)

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).