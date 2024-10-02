SELECT product_id, year AS first_year, quantity, price
FROM (
    SELECT *, MIN(year) OVER(PARTITION BY product_id) AS min_year
    FROM Sales
) AS SalesM
WHERE year = min_year