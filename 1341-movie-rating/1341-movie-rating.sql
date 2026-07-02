select
(
    select
    u.name
    from
    MovieRating m inner join Users u
    on m.user_id = u.user_id
    group by
    m.user_id
    order by
    count(m.rating) desc, u.name asc
    limit 1
) as results

UNION ALL

select
q.result as results
from
(
    select
    f.title as result,
    avg(m.rating) as avg_rating
    from
    MovieRating m inner join Movies f
    on m.movie_id = f.movie_id
    where
    m.created_at  >= '2020-02-01'
    and 
    m.created_at  < '2020-03-01'
    group by
    m.movie_id
    order by
    avg_rating desc, f.title asc
    limit 1
) as q