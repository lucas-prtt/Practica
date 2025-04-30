--1
SELECT c.customer_num, c.company, o.order_num
FROM customer c 
INNER JOIN orders o 
ON c.customer_num = o.customer_num
ORDER BY customer_num;

--2
SELECT o.order_num, i.item_num, p.description, i.manu_code, i.quantity, i.quantity * i.unit_price PrecioTotal
FROM orders o JOIN
items i ON o.order_num = i.order_num JOIN
product_types p ON i.stock_num = p.stock_num
WHERE o.order_num = 1004;

--3
SELECT o.order_num, i.item_num, p.description, i.manu_code, i.quantity,
i.quantity * i.unit_price 'Precio Total', m.manu_name "Nombre Fabricante" 
FROM orders o JOIN
items i ON o.order_num = i.order_num JOIN
product_types p ON i.stock_num = p.stock_num JOIN 
manufact m ON m.manu_code = i.manu_code
WHERE o.order_num = 1004;

--4
SELECT c.customer_num, c.fname, c.lname, c.company
FROM customer c 
JOIN orders o ON c.customer_num = o.customer_num;

--5
SELECT 
DISTINCT c.customer_num 'Numero de cliente',
c.fname 'Nombre', 
c.lname 'Apellido',
c.company 'Nombre compañia'
-- Al ser customer_num la PK, el DISTINCT aplica a todos los clientes
FROM customer c 
JOIN orders o ON c.customer_num = o.customer_num;

--6
SELECT m.manu_name 'Nombre Proveedor', 
p.stock_num 'Numero de stock', 
pt.description 'Descripcion' , 
u.unit 'Unidad' ,
p.unit_price 'Precio actual',
p.unit_price * 1.2 'Precio de Junio'
FROM products p 
JOIN manufact m ON p.manu_code = m.manu_code
JOIN product_types pt ON pt.stock_num = p.stock_num
JOIN units u ON u.unit_code = p.unit_code;

--7
SELECT i.item_num, pt.description  
FROM orders o JOIN 
items i ON o.order_num = i.order_num JOIN
product_types pt ON pt.stock_num = i.stock_num
WHERE o.order_num = 1004
