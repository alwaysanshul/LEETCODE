/* Write your PL/SQL query statement below */
select e.employee_id, (
case 
when
    e.name not like 'M%' 
    and mod(e.employee_id,2)=1
    then 
        e.salary 
    else
        0
end
) as bonus 
from employees e 
order by employee_id;