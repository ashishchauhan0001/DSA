

### SQL Revision Questions:

1. **Basic SELECT Queries:**
   - Retrieve all records from the table.
   - Select the employee names and their corresponding salaries.

2. **Filtering Data:**
   - Find employees who joined after the year 2000.
   - List employees whose salary is greater than 100,000.

3. **Aggregate Functions:**
   - Find the total number of employees.
   - Calculate the average salary of employees.
   - Find the highest and lowest salary in the table.

4. **Grouping Data:**
   - Group employees by their location and find the count of employees in each location.
   - `SELECT emp_location,count(emp_location) from employee GROUP BY emp_location LIMIT 100` first it will take all the emp location rows and then group by and also count in every group how many count?
   - Calculate the average salary for each location.

5. **Ordering Data:**
   - List all employees in ascending order of their join date.
   - List the top 5 highest-paid employees.

6. **JOIN Operations:**
   - (Assuming another table for departments) Retrieve employee names along with their department names.

7. **Subqueries:**
   - Find the employees who have the second-highest salary.
   - List employees who earn more than the average salary.

8. **String Functions:**
   - Find employees whose names start with the letter 'A'.
   - Find the length of each employee's name.

9. **Date Functions:**
   - Calculate the number of years each employee has been with the company.
   - Find employees who joined in the month of July.

10. **Updates and Deletes:**
    - Update the salary of employees who are located in 'New York' to 50,000.
    - Delete records of employees who joined before the year 1995.

### Interview-Style Questions Based on the Given Database Schema:

1. **Complex Queries:**
   - Find the top 3 locations with the highest average salary.
   - List employees who have the same join date.
   - `select * from employee e1 JOIN employee e2 ON e1.emp_id > e2.emp_id and e1.`joinDate`=e2.`joinDate` LIMIT 100`

2. **Data Integrity:**
   - Identify any employees with duplicate names.
   - `select * from employee e1 JOIN employee e2 ON e1.emp_id > e2.emp_id and e1.emp_name=e2.emp_name LIMIT 100`
   - Find and correct any employees with an invalid join date (e.g., '0000-00-00').

3. **Performance Optimization:**
   - How would you optimize a query that retrieves employees based on their location and salary range?
   - Discuss indexing strategies for this table to improve query performance.

4. **Schema Design:**
   - If you were to add a department table, how would you design it and establish a relationship with the current employee table?
   - What changes would you make to the current schema to support internationalization (e.g., handling different date formats)?

5. **Advanced SQL Functions:**
   - Write a query to find employees who joined in the last 5 years.
   - Using a window function, list employees along with their rank based on salary within their location.

### Example Queries:

1. **Retrieve all records from the table:**
   ```sql
   SELECT * FROM employees;
   ```

2. **Find employees who joined after the year 2000:**
   ```sql
   SELECT emp_name, joinDate 
   FROM employees 
   WHERE joinDate > '2000-01-01';
   ```

3. **Group employees by their location and find the count of employees in each location:**
   ```sql
   SELECT emp_location, COUNT(*) AS employee_count 
   FROM employees 
   GROUP BY emp_location;
   ```

4. **List the top 5 highest-paid employees:**
   ```sql
   SELECT emp_name, salary 
   FROM employees 
   ORDER BY salary DESC 
   LIMIT 5;
   ```

5. **Calculate the number of years each employee has been with the company:**
   ```sql
   SELECT emp_name, 
          joinDate, 
          YEAR(CURRENT_DATE) - YEAR(joinDate) AS years_with_company 
   FROM employees;
   ```

Feel free to run these queries on your database to practice and validate your understanding! If you need more specific queries or have any other questions, let me know.