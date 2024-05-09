SELECT Department.name AS Department, ranked.name AS Employee, ranked.salary AS Salary
FROM (
    SELECT id, name, salary, departmentID,
           DENSE_RANK() OVER (PARTITION BY departmentID ORDER BY salary DESC) AS r
    FROM Employee
) AS ranked
LEFT JOIN Department ON ranked.departmentId = Department.id
WHERE r <= 3;