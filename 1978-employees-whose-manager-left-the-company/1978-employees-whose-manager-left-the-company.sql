# Write your MySQL query statement below
SELECT 
    a.employee_id as employee_id
FROM 
    Employees a
WHERE 
    a.salary < 30000
    AND
    a.manager_id is NOT NULL
    AND
    a.manager_id NOT in (
        SELECT employee_id FROM Employees
    )
ORDER BY
    a.employee_id