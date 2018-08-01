# Write your MySQL query statement below
SELECT em.Name AS Employee
FROM Employee em INNER JOIN Employee mng
ON em.ManagerId = mng.Id
WHERE em.Salary > mng.Salary