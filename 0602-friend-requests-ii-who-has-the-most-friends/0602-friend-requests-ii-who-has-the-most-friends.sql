# Write your MySQL query statement below
select
d.id,
count(d.id) as num
from
(
    select requester_id as id from RequestAccepted 
    UNION ALL
    select accepter_id as id from RequestAccepted
) as d
group by
d.id 
order by
num desc
limit 1