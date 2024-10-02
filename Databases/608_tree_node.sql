SELECT t1.id AS id,
    CASE
        WHEN t1.id = (SELECT t2.id FROM Tree AS t2 WHERE t2.p_id IS NULL)
        THEN 'Root'
        WHEN t1.id IN (SELECT t3.p_id FROM Tree AS t3)
        THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree as t1