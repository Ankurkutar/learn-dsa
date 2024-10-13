# Write your MySQL query statement below
SELECT a.name AS Employee
FROM Employee a, Employee b
WHERE a.managerId = b.Id 
  AND a.salary > b.salary;
