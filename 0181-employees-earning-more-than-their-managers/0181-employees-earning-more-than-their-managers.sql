# Write your MySQL query statement below
SELECT 
    a.name as Employee
FROM
    Employee a JOIN Employee b

WHERE
    a.salary > b.salary 
    AND
    a.managerId = b.id