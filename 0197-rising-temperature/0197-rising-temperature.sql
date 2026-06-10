# Write your MySQL query statement below
select 
today.id as Id
from
Weather yesterday cross join Weather today
where 
DATEDIFF(today.recordDate, yesterday.recordDate) = 1
and
today.temperature > yesterday.temperature