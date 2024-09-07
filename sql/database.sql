
SELECT firstName, lastName, city, state
FROM Person AS p
    LEFT JOIN Address AS a ON p.personId = a.personId

SELECT email AS Email
FROM Person
GROUP BY
    email
HAVING
    COUNT(email) > 1

SELECT c.name Customers
FROM Customers c
    LEFT JOIN Orders o ON O.customerId = c.id
WHERE
    o.customerId IS NULL

DELETE p2
FROM Person AS p1
    JOIN Person AS p2 ON p1.email = p2.email
WHERE
    p1.id < p2.id

-- 177. Nth Highest Salary
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC LIMIT N, 1
  );
END;