WITH SalesM AS (
    SELECT seller_id, SUM(price) AS total_price
    FROM Sales
    GROUP BY seller_id
)

SELECT seller_id
FROM SalesM
WHERE total_price = (
    SELECT MAX(total_price)
    FROM SalesM
)