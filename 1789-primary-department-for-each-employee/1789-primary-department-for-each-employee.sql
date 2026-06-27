select
employee_id,
department_id 
from
Employee
where 
(employee_id, department_id)
in
(
    select
    employee_id, department_id
    from
    Employee 
    where 
    primary_flag = 'Y'
    UNION
    select
    employee_id, department_id
    from
    Employee 
    group by
    employee_id
    having
    COUNT(department_id) = 1
)