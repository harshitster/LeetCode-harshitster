SELECT e1.name AS Employee
FROM Employee as e1
LEFT JOIN Employee as e2 ON e1.managerID = e2.id
WHERE e1.salary > e2.salary