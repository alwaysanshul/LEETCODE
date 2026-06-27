
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag='Y' OR 
    employee_id in
    (SELECT employee_id
    FROM Employee
    Group by employee_id
    having count(employee_id)=1)

-- select
-- employee_id,
-- (
--     case 
--     when count(department_id) > 1 and primary_flag = 'Y' then department_id
--     when count(department_id) = 1 and primary_flag = 'N' then department_id
--     end
-- ) as department_id 
-- from
-- Employee
-- where 
-- (employee_id, department_id)
-- in
-- (
--     select
--     distinct employee_id, department_id
--     from
--     Employee 
--     where 
--     primary_flag = 'Y'

-- )