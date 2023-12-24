-- 180. Consecutive Numbers
-- 
-- Table: Logs
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+
-- 
-- In SQL, id is the primary key for this table.
-- id is an autoincrement column.
--  
-- Find all numbers that appear at least three times consecutively.
-- 
-- Return the result table in any order.
-- 
-- The result format is in the following example.
-- 
-- Example 1:
-- 
-- Input: 
-- Logs table:
-- +----+-----+
-- | id | num |
-- +----+-----+
-- | 1  | 1   |
-- | 2  | 1   |
-- | 3  | 1   |
-- | 4  | 2   |
-- | 5  | 1   |
-- | 6  | 2   |
-- | 7  | 2   |
-- +----+-----+
-- 
-- Output: 
-- +-----------------+
-- | ConsecutiveNums |
-- +-----------------+
-- | 1               |
-- +-----------------+
-- 
-- Explanation: 1 is the only number that appears consecutively for at least three times.

# Write your MySQL query statement below
SELECT DISTINCT a.Num AS ConsecutiveNums
FROM Logs a
INNER JOIN Logs b ON a.Num = b.Num and a.Id = b.Id + 1
INNER JOIN Logs c ON b.Num = c.Num and b.Id = c.Id + 1;

-- Tasks are the property of LeetCode (https://leetcode.com/) 
-- and users of this resource.
-- 
-- All solution code in this repository 
-- is the personal property of Vladimir Rukavishnikov
-- (vladimirrukavishnikovmail@gmail.com).