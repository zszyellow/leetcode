SELECT D.Name AS Department, E.Name AS Employee, E.Salary AS Salary
FROM
	Employee E,
	(SELECT DepartmentId, max(Salary) AS max FROM Employee GROUP BY DepartmentId) T,
	Department D
WHERE E.DepartmentId = T.DepartmentId 
    AND E.Salary = T.max
    AND E.DepartmentId = D.id