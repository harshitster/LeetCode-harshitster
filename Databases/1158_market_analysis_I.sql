WITH OrdersM AS (
    SELECT buyer_id, COUNT(*) AS orders_in_2019
    FROM Orders
    WHERE order_date BETWEEN "2019-01-01" AND "2019-12-31"
    GROUP BY buyer_id
)

SELECT user_id AS buyer_id, join_date, COALESCE(orders_in_2019, 0) AS orders_in_2019
FROM Users
LEFT JOIN OrdersM ON user_id = buyer_id