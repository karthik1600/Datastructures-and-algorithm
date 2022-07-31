```sql
UPDATE EMP
SET SALARY=15000 
WHERE JOB='Asst professor';
```
```sql
DELETE FROM EMP
WHERE ENAME='KG';
```

```sql
CREATE TABLE employee AS SELECT * FROM EMP;
```
DCL
```sql
grant select on emp to RA1911026010065
revoke select on emp to RA1911026010065;
```
TCL
```sql
Commit;
ROLLBACK;
SAVEPOINT SP1;
ROLLBACK TO SP1;
```
```sql
SELECT * FROM EMP
WHERE ENAME LIKE 'S%';

SELECT * FROM EMP
WHERE ENAME NOT LIKE 'S%';
```

```sql
SELECT * FROM EMP
WHERE SAL BETWEEN 5000 AND 15000;
```

Problem 9: Display the date 60 days before current date.
```sql
SELECT SYSDATE-60 FROM DUAL;
```
JOINS
```sql
SELECT * FROM STUDENT2 CROSS JOIN STUDENT3;
SELECT * from STUDENT2, STUDENT3 where STUDENT2.FID = STUDENT3.FID; # inner join or equi join
SELECT * from STUDENT2 NATURAL JOIN STUDENT3;
SELECT * FROM STUDENT2 LEFT OUTER JOIN STUDENT3 ON (STUDENT2.FID = STUDENT3.FID);
SELECT * FROM STUDENT2 RIGHT OUTER JOIN STUDENT3 ON (STUDENT2.FID = STUDENT3.FID);

# full outer join
SELECT * FROM STUDENT2
LEFT JOIN STUDENT3 ON (STUDENT2.FID=STUDENT3.FID)
UNION ALL
SELECT * FROM STUDENT2
RIGHT JOIN STUDENT3 ON (STUDENT2.FID=STUDENT3.FID);
```

---

## PLSQL
```sql
 dbms_output.put_line('Value of c: ' || c);  
```
Consider a declaration.
`SALARY EMP.SAL % TYPE;`
This declaration will declare a variable SALARY that has the same data type as column SAL of the EMP table.
```sql
DECLARE    
SALARY EMP.SAL % TYPE;  
ECODE EMP.empno % TYPE;   
BEGIN     
Ecode :=&Ecode;  
Select SAL into SALARY from EMP where EMPNO = ECODE;  
dbms_output.put_line('Salary of ' || ECODE || 'is = || salary');    
END;  
```
rowtype
```sql
DECLARE 
   customer_rec customers%rowtype; 
BEGIN 
   SELECT * into customer_rec 
   FROM customers 
   WHERE id = 5;  
   dbms_output.put_line('Customer ID: ' || customer_rec.id); 
   dbms_output.put_line('Customer Name: ' || customer_rec.name); 
   dbms_output.put_line('Customer Address: ' || customer_rec.address); 
   dbms_output.put_line('Customer Salary: ' || customer_rec.salary); 
END; 
```
```sql
DECLARE
    2 N NUMBER :=&N;
    3 S NUMBER:=0;
    4 R NUMBER;
    5 LEN NUMBER;
    6 M NUMBER;
    7 BEGIN 8 M:=N;
    9 LEN:=LENGTH(TO_CHAR(N));
    10 WHILE N>0 11
12 LOOP
13 R:=MOD(N,10);
14 S:=S+POWER(R,LEN); 15 N:=TRUNC(N/10);
    16 END LOOP;
    17 IF M=S
    18 THEN
    19 dbms_output.put_line('ARMSTRONG NUMBER');
    20 ELSE
    21 dbms_output.put_line('NOT ARMSTRONG NUMBER');
    22 END IF;
    23 END;
24 /
```
TRUNC(number)
MOD(num,num2);
```sql
DECLARE 
   a number; 
   b number; 
   c number;
PROCEDURE findMin(x IN number, y IN number, z OUT number) IS 
BEGIN 
   IF x < y THEN 
      z:= x; 
   ELSE 
      z:= y; 
   END IF; 
END;   
BEGIN 
   a:= 23; 
   b:= 45; 
   findMin(a, b, c); 
   dbms_output.put_line(' Minimum of (23, 45) : ' || c); 
END; 
```
```sql
DECLARE 
   a number; 
PROCEDURE squareNum(x IN OUT number) IS 
BEGIN 
  x := x * x; 
END;  
BEGIN 
   a:= 23; 
   squareNum(a); 
   dbms_output.put_line(' Square of (23): ' || a); 
END; 
```
## functions
```sql
DECLARE 
   a number; 
   b number; 
   c number; 
FUNCTION findMax(x IN number, y IN number)  
RETURN number 
IS 
    z number; 
BEGIN 
   IF x > y THEN 
      z:= x; 
   ELSE 
      Z:= y; 
   END IF;  
   RETURN z; 
END; 
BEGIN 
   a:= 23; 
   b:= 45;  
   c := findMax(a, b); 
   dbms_output.put_line(' Maximum of (23,45): ' || c); 
END; 
/ 
```
```sql
DECLARE 
   num number; 
   factorial number;  
   
FUNCTION fact(x number) 
RETURN number  
IS 
   f number; 
BEGIN 
   IF x=0 THEN 
      f := 1; 
   ELSE 
      f := x * fact(x-1); 
   END IF; 
RETURN f; 
END;  

BEGIN 
   num:= 6; 
   factorial := fact(num); 
   dbms_output.put_line(' Factorial '|| num || ' is ' || factorial); 
END; 
```
# Cursor
```sql
DECLARE  
   total_rows number(2); 
BEGIN 
   UPDATE customers 
   SET salary = salary + 500; 
   IF sql%notfound THEN 
      dbms_output.put_line('no customers selected'); 
   ELSIF sql%found THEN 
      total_rows := sql%rowcount;
      dbms_output.put_line( total_rows || ' customers selected '); 
   END IF;  
END; 
/      
```
```sql
DECLARE 
   c_id customers.id%type; 
   c_name customers.name%type; 
   c_addr customers.address%type; 
   CURSOR c_customers is 
      SELECT id, name, address FROM customers; 
BEGIN 
   OPEN c_customers; 
   LOOP 
   FETCH c_customers into c_id, c_name, c_addr; 
      EXIT WHEN c_customers%notfound; 
      dbms_output.put_line(c_id || ' ' || c_name || ' ' || c_addr); 
   END LOOP; 
   CLOSE c_customers; 
END; 
/
```
---
# Triggers
```sql
CREATE OR REPLACE TRIGGER display_salary_changes 
BEFORE DELETE OR INSERT OR UPDATE ON customers 
FOR EACH ROW 
WHEN (NEW.ID > 0) 
DECLARE 
   sal_diff number; 
BEGIN 
   sal_diff := :NEW.salary  - :OLD.salary; 
   dbms_output.put_line('Old salary: ' || :OLD.salary); 
   dbms_output.put_line('New salary: ' || :NEW.salary); 
   dbms_output.put_line('Salary difference: ' || sal_diff); 
END; 
/ 
```