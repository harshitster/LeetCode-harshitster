SELECT Department.name AS Department, Employee.name AS Employee, Employee.salary AS Salary
FROM Employee 
LEFT JOIN Department ON Employee.departmentId = Department.id
WHERE (departmentId, salary) IN (
    SELECT departmentId, MAX(salary)
    FROM Employee
    GROUP BY departmentId
)