WITH 
F1 AS (
    SELECT followee, COUNT(*) AS num
    FROM Follow
    GROUP BY followee
    HAVING COUNT(*) >= 1
),
F2 AS (
    SELECT follower
    FROM Follow
    GROUP BY follower
    HAVING COUNT(*) >= 1
)
SELECT F1.followee AS follower, F1.num
FROM F1
JOIN F2 ON F1.followee = F2.follower
ORDER BY F1.followee