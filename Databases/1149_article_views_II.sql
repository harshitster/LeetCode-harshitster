# Write your MySQL query statement below
SELECT DISTINCT viewer_id AS id
FROM (
    SELECT viewer_id, view_date, COUNT(DISTINCT article_id) AS article_count
    FROM Views
    GROUP BY viewer_id, view_date
) AS ViewsM
WHERE article_count > 1
ORDER BY viewer_id 