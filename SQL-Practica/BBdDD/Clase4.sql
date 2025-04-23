SELECT * INTO #clientes FROM customer ;

INSERT INTO #clientes 
(Customer_num, Fname, Lname, Company, State, City) 
VALUES 
(144, 'Agustin', 'Creevy', 'Jaguares SA', 'CA', 'Los Angeles');

SELECT * INTO #clientesCalifornia FROM customer WHERE state = 'CA';

INSERT INTO #clientes 
SELECT 155, fname, lname, company, address1, address2,
city, state, zipcode, phone, customer_num_referedBy, status
FROM #clientes WHERE customer_num = 103;

SELECT * FROM #clientes
WHERE customer_num IN (155, 103);

DELETE FROM #clientes 
WHERE zipcode BETWEEN 94000 AND 94050 AND city LIKE 'M%';

UPDATE #clientes
SET state = 'AK', address2 = 'Barrio Las Heras' 
WHERE state = 'CO';

UPDATE #clientes
SET phone = concat('1', phone)
WHERE phone IS NOT NULL;

UPDATE #clientes -- revertir cambio
SET phone = RIGHT(phone, LEN(phone)-1)
WHERE phone IS NOT NULL;

SELECT * FROM #clientes
