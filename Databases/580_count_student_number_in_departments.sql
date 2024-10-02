SELECT D.dept_name AS dept_name, COUNT(student_id) AS student_number
FROM Department AS D
LEFT JOIN Student AS S ON D.dept_id = S.dept_id
GROUP BY D.dept_id
ORDER BY student_number DESC, dept_name