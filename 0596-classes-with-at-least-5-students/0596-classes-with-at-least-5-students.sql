# Write your MySQL query statement below
select
class
from
Courses
where
(student, class) 
in 
(
    select
    student, class
    from
    Courses
    group by
    class
    having
    count(class) >= 5
)

