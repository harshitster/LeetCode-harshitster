SELECT c.name AS Customers
FROM Customers as c
LEFT JOIN Orders AS o ON o.customerId = c.id
WHERE o.id IS NULL