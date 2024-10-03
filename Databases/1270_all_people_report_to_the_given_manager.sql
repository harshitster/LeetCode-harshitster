SELECT e1.employee_id AS employee_id
FROM Employees AS e1
LEFT JOIN Employees AS e2 ON e2.employee_id = e1.manager_id
LEFT JOIN Employees AS e3 ON e3.employee_id = e2.manager_id
WHERE e3.manager_id = 1 AND e1.employee_id != 1