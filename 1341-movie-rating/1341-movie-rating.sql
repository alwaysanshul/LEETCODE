# Write your MySQL query statement below

(select 
    u.name as results
from    
    Users u join MovieRating m
    on u.user_id = m.user_id
group by 
    m.user_id
order by 
    count(m.movie_id) DESC , u.name ASC
limit 1
)
union all
(
select 
    m.title as results
from 
    Movies m join MovieRating r
    on m.movie_id = r.movie_id
where
   r.created_at >= '2020-02-01' and r.created_at <'2020-03-01'
group by
    r.movie_id 
order by
    AVG(r.rating) desc , m.title ASC
limit 1
)