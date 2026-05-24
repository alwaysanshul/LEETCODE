# Write your MySQL query statement below
select 
    DATE_FORMAT(trans_date,'%Y-%m') as month,
    country, 
    count(state) as trans_count,
    sum(case
        when state = 'approved' then 1
        when state = 'declined' then 0
    end) as approved_count,
    sum(amount) as trans_total_amount,
    sum(case
        when state = 'approved' then amount
        when state = 'declined' then 0
    end) as approved_total_amount
from
    Transactions
group by
    country, DATE_FORMAT(trans_date,'%Y-%m')
    