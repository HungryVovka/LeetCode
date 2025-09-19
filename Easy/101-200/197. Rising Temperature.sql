-- 197. Rising Temperature
-- Table: Weather
-- 
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | recordDate    | date    |
-- | temperature   | int     |
-- +---------------+---------+
-- id is the column with unique values for this table.
-- There are no different rows with the same recordDate.
-- This table contains information about the temperature on a certain day.
--  
-- 
-- Write a solution to find all dates' id with higher temperatures compared to its previous dates (yesterday).
-- 
-- Return the result table in any order.
-- 
-- The result format is in the following example.
-- 
--  
-- 
-- Example 1:
-- 
-- Input: 
-- Weather table:
-- +----+------------+-------------+
-- | id | recordDate | temperature |
-- +----+------------+-------------+
-- | 1  | 2015-01-01 | 10          |
-- | 2  | 2015-01-02 | 25          |
-- | 3  | 2015-01-03 | 20          |
-- | 4  | 2015-01-04 | 30          |
-- +----+------------+-------------+
-- Output: 
-- +----+
-- | id |
-- +----+
-- | 2  |
-- | 4  |
-- +----+
-- Explanation: 
-- In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
-- In 2015-01-04, the temperature was higher than the previous day (20 -> 30).

-- MySQL
# Write your MySQL query statement below
SELECT Today.id AS id
FROM Weather AS Today
JOIN Weather AS Yesterday
    ON Today.recordDate = DATE_ADD(Yesterday.recordDate, INTERVAL 1 DAY)
WHERE Today.temperature > Yesterday.temperature
ORDER BY Today.id;

-- PostgreSQL
-- Write your PostgreSQL query statement below
SELECT Today.id AS id
FROM Weather AS Today
JOIN Weather AS Yesterday
    ON Today.recordDate = (Yesterday.recordDate + INTERVAL '1 day')
WHERE Today.temperature > Yesterday.temperature
ORDER BY Today.id;

-- MS SQL Server
/* Write your T-SQL query statement below */
SELECT Today.id AS id
FROM Weather AS Today
JOIN Weather AS Yesterday
    ON Today.recordDate = DATEADD(day, 1, Yesterday.recordDate)
WHERE Today.temperature > Yesterday.temperature
ORDER BY Today.id;

-- Tasks are the property of LeetCode (https://leetcode.com/) 
-- and users of this resource.
-- 
-- All solution code in this repository 
-- is the personal property of Vladimir Rukavishnikov
-- (vladimirrukavishnikovmail@gmail.com).