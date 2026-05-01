# Write your MySQL query statement below
SELECT 
    a.id as id,
    a.movie as movie,
    a.description as description,
    a.rating as rating
FROM 
    Cinema a
WHERE 
    a.id % 2 != 0 
    AND
    description != 'boring'
ORDER BY
    a.rating DESC