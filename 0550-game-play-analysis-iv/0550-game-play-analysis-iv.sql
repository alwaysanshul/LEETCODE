# Write your MySQL query statement below
select 
ROUND(
    SUM(
        case
        when (player_id, DATE_ADD(event_date, INTERVAL 1 DAY)) in (select player_id, event_date from Activity) then 1
        else 0
        end
    ) / (select COUNT(distinct player_id) from Activity) 
,2) as fraction 
from 
Activity
where
(player_id, event_date)
in
(
    select player_id, MIN(event_date)
    from Activity
    group by player_id
)