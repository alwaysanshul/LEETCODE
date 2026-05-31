# Write your MySQL query statement below
select
    request_at as Day,
    ROUND(
        SUM(
            CASE WHEN status != 'completed' then 1
            ELSE 0
            END 
        ) * 1.0 / COUNT(status)
    , 2)
    as `Cancellation Rate`

from 
    (
        select Trips.* 
        from Trips join Users u1
        on Trips.client_id = u1.users_id and u1.banned != "Yes"

        join Users u2 
        on Trips.driver_id = u2.users_id and u2.banned != "Yes"
    ) as dtable
where 
    request_at between '2013-10-01' and '2013-10-03'
group by 
    request_at
order by
    request_at