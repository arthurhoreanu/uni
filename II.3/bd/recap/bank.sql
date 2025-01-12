create database Bank;

CREATE TABLE Bank ( -- 1:n Konto
    bank_id INT PRIMARY KEY,
    name VARCHAR(100) UNIQUE NOT NULL,
    country VARCHAR(50) NOT NULL,
    founding_year INT NOT NULL
);

CREATE TABLE Kunde ( -- 1:n Konto
    customer_id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    birth_date DATE NOT NULL,
    address VARCHAR(255) NOT NULL
);

CREATE TABLE Konto (
    account_id INT PRIMARY KEY,
    account_number VARCHAR(20) UNIQUE NOT NULL,
    currency VARCHAR(3) NOT NULL,
    opening_date DATE NOT NULL,
    bank_id INT NOT NULL,
    customer_id INT NOT NULL,
    CONSTRAINT fk_konto_bank FOREIGN KEY (bank_id) REFERENCES Bank(bank_id) ON DELETE CASCADE,
    CONSTRAINT fk_konto_customer FOREIGN KEY (customer_id) REFERENCES Kunde(customer_id) ON DELETE CASCADE
);

CREATE TABLE Transaktion ( -- 1:n Transaktion
    transaction_id INT PRIMARY KEY,
    from_account INT NOT NULL,
    to_account INT NOT NULL,
    date DATE NOT NULL,
    fee DECIMAL(10, 2) NOT NULL,
    amount DECIMAL(10, 2) NOT NULL,
    CONSTRAINT fk_trans_from_account FOREIGN KEY (from_account) REFERENCES Konto(account_id) ON DELETE CASCADE,
    CONSTRAINT fk_trans_to_account FOREIGN KEY (to_account) REFERENCES Konto(account_id) ON UPDATE NO ACTION
);

INSERT INTO Bank (bank_id, name, country, founding_year)
VALUES (1, 'Banca Transilvania', 'Romania', 1993),
        (2, 'BCR', 'Romania', 1990);

INSERT INTO Kunde(customer_id, name, birth_date, address)
VALUES (1, 'Ion Popescu', '1990-08-02', 'Adresa lui Ion'),
        (2, 'Andreea Ionescu', '2000-04-01', 'Adresa Andreeai');

INSERT INTO Konto(account_id, account_number, currency, opening_date, bank_id, customer_id)
VALUES (1, 'BTRLEURCRT0001', 'EUR', '2024-12-12', 1, 1),
(2, 'BTRLRONCRT0001', 'RON', '2024-11-14', 1, 1),
(3, 'BCREURCRT0001', 'EUR', '2023-12-22', 2, 1),
(4, 'BCRRONCRT0001', 'RON', '2023-12-22', 2, 1),
(5, 'BTRLEURCRT0002', 'EUR', '2024-12-12', 1, 2),
(6, 'BTRLRONCRT0002', 'RON', '2024-11-14', 1, 2),
(7, 'BCREURCRT0002', 'EUR', '2023-12-22', 2, 2),
(8, 'BCRRONCRT0002', 'RON', '2023-12-22', 2, 2);

INSERT INTO Transaktion(transaction_id, from_account, to_account, [date], fee, amount)
VALUES
(1, 1, 7, '2024-12-30', 1.0, 500.0),
(2, 8, 2, '2025-01-01', 2.0, 1000.0),
(3, 3, 5, '2025-01-02', 1.0, 100.0),
(4, 5, 3, '2025-01-03', 2.5, 50.0),
(5, 7, 1, '2024-01-01', 2.5, 300.0),
(6, 2, 8, '2024-01-05', 3.0, 120.0);

select b.name as 'Bank Name',
    SUM(t.fee) as 'Sum of fees on intransactions in EUR'
from Bank b
join Konto k on b.bank_id = k.bank_id
join Transaktion t on t.from_account = k.account_id
where k.currency='EUR' AND t.[date] >= '2024-01-01' AND t.[date] <= '2024-12-31'
group by b.name;

SELECT r.Name AS 'Customer Name',
       SUM(t.Amount) AS 'Amount of RON received from a single customer',
       s.Name AS 'Sender'
FROM Transaktion t
JOIN Konto rK ON t.to_account = rK.account_id
JOIN Kunde r ON rK.customer_id = r.customer_id
JOIN Konto sK ON t.from_account = sK.account_id
JOIN Kunde s ON sK.customer_id = s.customer_id
WHERE rK.Currency = 'RON'
GROUP BY r.customer_id, r.Name, s.customer_id, s.Name
HAVING COUNT(DISTINCT s.customer_id) = 1;