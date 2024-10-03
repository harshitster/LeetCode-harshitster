# Write your MySQL query statement below
WITH ids AS ((
        SELECT requester_id AS id
        FROM RequestAccepted
    ) 
    UNION ALL
    (
        SELECT accepter_id AS id
        FROM RequestAccepted
    )
)

SELECT id, counts AS num
FROM (
    SELECT id, COUNT(id) AS counts, RANK() OVER(ORDER BY COUNT(id) DESC) rnk 
    FROM ids
    GROUP BY id
) AS idsm
WHERE rnk = 1