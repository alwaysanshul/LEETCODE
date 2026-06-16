# Write your MySQL query statement below
select 
p.product_id,
(case 
    when sum(u.units) is null then 0
    else round(sum(p.price*u.units)/ sum(u.units) ,2)
    end 
) as average_price
from
Prices p left join UnitsSold u
on p.product_id = u.product_id 
and (u.purchase_date >= start_date and u.purchase_date <= end_date)
group by
p.product_id