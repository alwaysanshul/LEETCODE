# Write your MySQL query statement below
select (select name from Employee where id = e.managerId) as name
from
Employee e
where 
e.managerId in (select id from Employee)
group by 
e.managerId
having 
count(*) > 4

