CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
 SET N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      
      SELECT distinct salary FROM Employee ORDER BY salary desc 
      limit N,1
  );
  END