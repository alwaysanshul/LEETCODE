select
m.employee_id as employee_id,
m.name as name,
COUNT(e.reports_to) as reports_count,
ROUND(AVG(e.age)) as average_age
from
Employees e 
inner join
Employees m
on
e.reports_to = m.employee_id
group by
m.employee_id
order by
m.employee_id
