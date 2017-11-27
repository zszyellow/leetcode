SELECT D.Name AS Department, E1.Name AS Employee, E1.Salary AS Salary
FROM Employee E1 
JOIN Department D ON E1.DepartmentId = D.Id
WHERE 3 > (SELECT COUNT(DISTINCT(E2.Salary)) 
                  FROM Employee E2 
                  WHERE E2.Salary > E1.Salary 
                  AND E1.DepartmentId = E2.DepartmentId
          );