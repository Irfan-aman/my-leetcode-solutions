CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE offset_val INT;
  DECLARE result INT;

  IF N <= 0 THEN
    RETURN NULL;
  END IF;

  SET offset_val = N - 1;

  SET result = (
    SELECT salary
    FROM (
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC
    ) AS distinct_salaries
    LIMIT offset_val, 1
  );

  RETURN result;
END