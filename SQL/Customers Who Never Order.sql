# Write your MySQL query statement below
SELECT cus.Name AS Customers
FROM Customers cus LEFT JOIN Orders ord
ON cus.Id = ord.CustomerId 
GROUP BY cus.Id
HAVING COUNT(ord.CustomerId) = 0