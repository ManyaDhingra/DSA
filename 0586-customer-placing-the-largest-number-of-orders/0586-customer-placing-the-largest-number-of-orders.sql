# Write your MySQL query statement below
SELECT customer_number FROM ORDERS
GROUP BY CUSTOMER_NUMBER 
ORDER BY COUNT(*) DESC
LIMIT 1;