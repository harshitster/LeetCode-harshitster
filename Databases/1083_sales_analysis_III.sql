SELECT Sales.buyer_id
FROM Sales
LEFT JOIN Product ON Product.product_id = Sales.product_id
GROUP BY Sales.buyer_id
HAVING SUM(CASE WHEN Product.product_name = 'iPhone' THEN 1 ELSE 0 END) = 0 AND
SUM(CASE WHEN Product.product_name = 'S8' THEN 1 ELSE 0 END) > 0