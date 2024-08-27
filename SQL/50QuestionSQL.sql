-- Active: 
--  SOLUTION BY ASHISH CHAUHAN

1. Write an SQL query to fetch “FIRST_NAME” from the Worker table using the alias name as <WORKER_NAME>.

SELECT First_Name as Worker_Name from worker;

2. Write an SQL query to fetch “FIRST_NAME” from the Worker table in upper case.

Select upper(First_Name) from worker;

3. Write an SQL query to fetch unique values of DEPARTMENT from the Worker table.

select Department from worker GROUP BY Department;

4. Write an SQL query to print the first three characters of FIRST_NAME from the Worker table.

select SUBSTR(`First_Name`,1,3) from worker;

5. Write an SQL query to find the position of the alphabet ('b') in the first name column 'Amitabh' from the Worker table.

select INSTR(`First_Name`,'b') from worker where `First_Name`='Amitabh';

6. Write an SQL query to print the FIRST_NAME from the Worker table after removing white spaces from the right side.

SELECT RTRIM(First_Name) from worker;

7. Write an SQL query to print the `DEPARTMENT` from the Worker table after removing white spaces from the left side.

select LTRIM(department) from worker;

8. Write an SQL query that fetches the unique values of `DEPARTMENT` from the Worker table and prints its length.

SELECT DISTINCT(`Department`), LENGTH(department) from worker;

9. Write an SQL query to print the `FIRST_NAME` from the Worker table after replacing ‘a’ with ‘A’.

select REPLACE(First_Name, "a" , "A" ) from worker;

10. Write an SQL query to print the `FIRST_NAME` and `LAST_NAME` from the Worker table into a single column `COMPLETE_NAME`. A space character should separate them.

SELECT CONCAT(First_Name,' ',Last_Name) as Complete_Name from worker;

11. Write an SQL query to print all Worker details from the Worker table ordered by `FIRST_NAME` in ascending order.

select * from worker ORDER BY `First_Name`;

12. Write an SQL query to print all Worker details from the Worker table ordered by `FIRST_NAME` ascending and `DEPARTMENT` descending.

SELECT * from worker ORDER BY `First_Name`,`Department` desc;

13. Write an SQL query to print details for Workers with the first name as “Vipul” and “Satish” from the Worker table.

select * from worker where `First_Name` IN ('Vipul','Satish');

14. Write an SQL query to print details of workers excluding first names, “Vipul” and “Satish” from the Worker table.

select * from worker where `First_Name` NOT IN ('Vipul','Satish');

15. Write an SQL query to print details of Workers with the `DEPARTMENT` name as “Admin*”.

select * from worker where `Department`='Admin';

16. Write an SQL query to print details of the Workers whose `FIRST_NAME` contains ‘a’.

select * from worker where `First_Name` like '%a%';

17. Write an SQL query to print details of the Workers whose `FIRST_NAME` ends with ‘a’.

select `First_Name` from worker where `First_Name` like '%a';

18. Write an SQL query to print details of the Workers whose `FIRST_NAME` ends with ‘h’ and contains six alphabets.

select * from worker where `First_Name` like '_____h';

19. Write an SQL query to print details of the Workers whose `SALARY` lies between 100000 and 500000.

-- select * from worker where `Salary`>=100000 AND `Salary`=<500000;

select * from worker where `Salary` BETWEEN 100000 AND 500000;

20. Write an SQL query to print details of the Workers who have joined in Feb’2014.

-- select * from worker where `Joining_Date` BETWEEN '2014-02-01' AND '2014-02-28';

select * from worker where YEAR(Joining_Date)=2014 AND MONTH(Joining_Date)='02';

21. Write an SQL query to fetch the count of employees working in the department ‘Admin’.

select count(*) as Admin_Count from worker where `Department`='Admin';

22. Write an SQL query to fetch worker full names with salaries >= 50000 and <= 100000.

select CONCAT(First_name,' ',Last_Name) as Full_Name from worker where `Salary` BETWEEN 50000 AND 100000;

23. Write an SQL query to fetch the number of workers for each department in descending order.

SELECT count(*),department from worker GROUP BY `Department` ORDER BY count(*) desc;

-- SELECT count(*) as xx,`Department` from worker GROUP BY `Department` ORDER BY xx DESC;

24. Write an SQL query to print details of the Workers who are also Managers.

select w.* from worker w join title t on 
w.`Worker_ID`=t.`WORKER_REF_ID` 
where  t.`WORKER_TITLE`='Manager'; 


25. Write an SQL query to fetch the number (more than 1) of the same titles in the ORG of different types.

select count(worker_title) from title GROUP BY `WORKER_TITLE` HAVING count(`WORKER_TITLE`)>1;
--  title wale table me se krna h ye org mtlb worker_title hai.

26. Write an SQL query to show only odd rows from a table.

select * from worker where MOD(worker_id,2)<>0;

27. Write an SQL query to show only even rows from a table.

select * from worker where MOD(worker_id,2)=0;

28. Write an SQL query to clone a new table from another table.

create table clone like worker;
insert into clone SELECT * from worker;

29. Write an SQL query to fetch intersecting records of two tables.

select worker.* from Worker join clone on worker.`Worker_ID`=clone.`Worker_ID`;
-- select worker.* from worker join clone using(`Worker_ID`);


30. Write an SQL query to show records from one table that another table does not have.

select * from worker w left join clone c on w.`Worker_ID`=c.`Worker_ID`
where c.`Worker_ID` IS NULL;

31. Write an SQL query to show the current date and time.

select now();

32. Write an SQL query to show the top n (say 5) records of a table ordered by descending salary.

select * from worker ORDER BY `Salary` desc limit 5 ;

33. Write an SQL query to determine the nth (say n=5) highest salary from a table.

-- select salary from worker ORDER BY salary DESC limit 1 offset 4;
select * from worker ORDER BY `Salary` desc limit 4,1;

--  dekho bhai limit offset,limitvalue

34. Write an SQL query to determine the 5th highest salary without using the LIMIT keyword.

-- select max(`Salary`) 
-- from worker 
-- where salary <(
--     select max(`Salary`) from worker where salary <(
--     select max(`Salary`) from worker where salary <(
--     select max(`Salary`) from worker where salary <(
--     select max(`Salary`) from worker))));

select salary from worker w1 where 4=(
    select count(DISTINCT(`Salary`)) from worker w2
    where w2.`Salary`>=w1.`Salary`
);


35. Write an SQL query to fetch the list of employees with the same salary.

--  select w1.* from worker w1 join worker w2 on w1.`Worker_ID`<>w2.`Worker_ID` AND w1.`Salary`=w2.`Salary`;
select * from worker w1 where w1.`Salary`IN (
    select `Salary` from worker w2 where w1.`Worker_ID`<>w2.`Worker_ID`
);

36. Write an SQL query to show the second-highest salary from a table using a sub-query.

select max(`Salary`) from worker where `Salary` NOT IN (
    select max(`Salary`) from worker
);

37. Write an SQL query to show one row twice in results from a table.

select * from worker
UNION ALL
select * from worker ORDER BY `Worker_ID`;


38. Write an SQL query to list `worker_id` who does not get a bonus.



select w.* from worker w where w.`Worker_ID` NOT IN(
    select b.`WORKER_REF_ID` from bonus b
);

select w.* from worker w left join bonus b on w.`Worker_ID`=b.`WORKER_REF_ID`
where b.`WORKER_REF_ID` IS NULL;




39. Write an SQL query to fetch the first 50% of records from a table.

SELECT * from worker where `Worker_ID`<=(
    select count(*)/2 from worker
);

40. Write an SQL query to fetch the departments that have fewer than 4 people in them.

 select count(*),`Department` from worker GROUP BY `Department` HAVING count(*)<4;

41. Write an SQL query to show all departments along with the number of people in each.

select department,count(*) from worker GROUP BY `Department`;

42. Write an SQL query to show the last record from a table.

select * from worker where `Worker_ID`=(
    select max(`Worker_ID`) from worker
);

43. Write an SQL query to fetch the first row of a table.

select * from worker limit 1;
--  but the thing is the data stores in table is unordered..
--   so you need some other to find you can do order by asc. so that you can get the first row data.

44. Write an SQL query to fetch the last five records from a table.

(select * from worker order by `Worker_ID` DESC limit 5) order by `Worker_ID`;

45. Write an SQL query to print the name of employees having the highest salary in each department.

--  how to create a derived table this is below 'temp' is the derived table.
select w.department,w.first_name,w.salary FROM 
(select department,max(salary) as maxSalary from worker GROUP BY `Department`) temp inner join worker w on temp.`Department`=w.`Department` and temp.maxSalary=w.`Salary`;

46. Write an SQL query to fetch three max salaries from a table using a co-related subquery.

select DISTINCT(w1.salary) from worker w1 where 3>=(select count(DISTINCT(w2.salary)) from worker w2 where w1.`Salary`<=w2.`Salary`);

47. Write an SQL query to fetch three min salaries from a table using a co-related subquery.

select DISTINCT(w1.salary) from worker w1 where 3>=(select count(DISTINCT(w2.salary)) from worker w2 where w1.`Salary`>=w2.`Salary`);

48. Write an SQL query to fetch nth max salaries from a table using co-related subquery.
--  these can be done by using LIMIT and OFFSET and ORDER BY whatever they are asking

select DISTINCT(w1.salary) from worker w1 where n>=(select count(DISTINCT(w2.salary)) from worker w2 where w1.`Salary`>=w2.`Salary`);

49. Write an SQL query to fetch departments along with the total salaries paid for each of them.

select department,sum(salary) as total_salary from worker GROUP BY `Department`;

50. Write an SQL query to fetch the names of workers who earn the highest salary.

select * from worker where `Salary`IN ( select max(`Salary`) from worker);