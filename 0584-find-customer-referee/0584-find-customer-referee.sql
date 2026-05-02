# Write your MySQL query statement below
SELECT 
    a.name as name
FROM 
    Customer a
WHERE 
    a.referee_id != 2
    OR
    a.referee_id is NULL