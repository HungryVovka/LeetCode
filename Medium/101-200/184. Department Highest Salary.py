# 184. Department Highest Salary
# 
# Table: Employee
# 
# +--------------+---------+
# | Column Name  | Type    |
# +--------------+---------+
# | id           | int     |
# | name         | varchar |
# | salary       | int     |
# | departmentId | int     |
# +--------------+---------+
# 
# id is the primary key (column with unique values) for this table.
# departmentId is a foreign key (reference columns) of the ID from the 
# Department table.
# Each row of this table indicates the ID, name, and salary of an employee. 
# It also contains the ID of their department.
#  
# 
# Table: Department
# 
# +-------------+---------+
# | Column Name | Type    |
# +-------------+---------+
# | id          | int     |
# | name        | varchar |
# +-------------+---------+
# 
# id is the primary key (column with unique values) for this table. 
# It is guaranteed that department name is not NULL.
# Each row of this table indicates the ID of a department and its name.
#  
# 
# Write a solution to find employees who have the highest salary in each of 
# the departments.
# 
# Return the result table in any order.
# 
# The result format is in the following example.
# 
# 
# Example 1:
# 
# Input: 
# Employee table:
# +----+-------+--------+--------------+
# | id | name  | salary | departmentId |
# +----+-------+--------+--------------+
# | 1  | Joe   | 70000  | 1            |
# | 2  | Jim   | 90000  | 1            |
# | 3  | Henry | 80000  | 2            |
# | 4  | Sam   | 60000  | 2            |
# | 5  | Max   | 90000  | 1            |
# +----+-------+--------+--------------+
# 
# Department table:
# +----+-------+
# | id | name  |
# +----+-------+
# | 1  | IT    |
# | 2  | Sales |
# +----+-------+
# Output: 
# +------------+----------+--------+
# | Department | Employee | Salary |
# +------------+----------+--------+
# | IT         | Jim      | 90000  |
# | Sales      | Henry    | 80000  |
# | IT         | Max      | 90000  |
# +------------+----------+--------+
# 
# Explanation: Max and Jim both have the highest salary in the IT 
# department and Henry has the highest salary in the Sales department.

import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    max_salary_by_department = (
        employee
        .groupby("departmentId", as_index=False)["salary"]
        .max()
        .rename(columns={"salary": "max_salary"})
    )
    top_employees = employee.merge(
        max_salary_by_department,
        on="departmentId",
        how="inner"
    )
    top_employees = top_employees[
        top_employees["salary"] == top_employees["max_salary"]
    ]
    answer = top_employees.merge(
        department,
        left_on="departmentId",
        right_on="id",
        how="inner"
    )
    return answer[["name_y", "name_x", "salary"]].rename(
        columns={
            "name_y" : "Department",
            "name_x" : "Employee",
            "salary" : "Salary"
        }
    )

# or

import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    emp = employee[["name", "salary", "departmentId"]]
    max_salary = emp.groupby("departmentId")["salary"].transform("max")
    top_emp = emp[emp["salary"].eq(max_salary)]

    answer = top_emp.merge(
        department[["id", "name"]],
        left_on="departmentId",
        right_on="id",
        how="inner",
        copy=False
    )
    return answer.rename(
        columns={
            "name_y" : "Department",
            "name_x" : "Employee",
            "salary" : "Salary"
        }
    )[["Department", "Employee", "Salary"]]

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).