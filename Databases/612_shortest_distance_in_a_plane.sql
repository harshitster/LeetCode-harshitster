# Write your MySQL query statement below
SELECT ROUND(MIN(SQRT(POW(p1.x - p2.x, 2) + POW(p1.y - p2.y, 2))), 2) AS shortest
FROM Point2D AS p1
LEFT JOIN Point2D as p2 ON p1.x != p2.x OR p1.y != p2.y