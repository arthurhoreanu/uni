create database Auto;

CREATE TABLE Besitzer (
    owner_id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    address VARCHAR(255) NOT NULL,
    birth_date DATE NOT NULL,
    phone VARCHAR(15) NOT NULL
);

CREATE TABLE Fahrzeug (
    vehicle_id INT PRIMARY KEY,
    license_plate VARCHAR(20) UNIQUE NOT NULL,
    brand VARCHAR(50) NOT NULL,
    model VARCHAR(50) NOT NULL,
    year INT NOT NULL,
    colour VARCHAR(20) NOT NULL,
    owner_id INT NOT NULL,
    CONSTRAINT fk_vehicle_owner FOREIGN KEY (owner_id) REFERENCES Besitzer(owner_id) ON DELETE CASCADE
);

CREATE TABLE Versicherungsvertrag (
    insurance_id INT PRIMARY KEY,
    vehicle_id INT NOT NULL,
    start_date DATE NOT NULL,
    end_date DATE NOT NULL,
    premium DECIMAL(10, 2),
    CONSTRAINT fk_insurance_vehicle FOREIGN KEY (vehicle_id) REFERENCES Fahrzeug(vehicle_id) ON DELETE CASCADE
);

CREATE TABLE Unfall (
    accident_id INT PRIMARY KEY,
    vehicle_id INT NOT NULL,
    date DATE NOT NULL,
    location VARCHAR(255),
    description VARCHAR(255),
    damage DECIMAL(10, 2),
    CONSTRAINT fk_accident_vehicle FOREIGN KEY (vehicle_id) REFERENCES Fahrzeug(vehicle_id) ON DELETE CASCADE
);

INSERT INTO Besitzer
VALUES
(1, 'name', 'address', '2000-12-12', '0770123458'),
(2, 'name2', 'address2', '2002-12-12', '0770465789');

INSERT INTO Fahrzeug
VALUES
(1, 'CJ79TUA', 'brand', 'model', 2005, 'colour', 1),
(2, 'AR09AYR', 'brand2', 'model2', 2010, 'colour2', 2);

INSERT INTO Unfall
VALUES
(1, 2, '2024-12-12', 'cluj', 'desc', 350.0);

INSERT INTO Versicherungsvertrag
VALUES
(1, 1, '2024-12-12', '2025-12-12', 10.0);

select b.name as 'Owner',
f.brand as 'Brand',
f.model as 'Model'
from Besitzer b
join Fahrzeug f on f.owner_id = b.owner_id
where not exists(
    select *
    from Unfall u
    WHERE u.vehicle_id = f.vehicle_id
);

-- ALTERNATIVE
SELECT b.Name AS Owner,
       f.Brand AS Brand,
       f.Model AS Model
FROM Besitzer b
JOIN Fahrzeug f ON b.owner_id = f.owner_id
LEFT JOIN Unfall u ON f.vehicle_id = u.vehicle_id
WHERE u.accident_id IS NULL;

SELECT SUM(u.damage) AS TotalDamage
FROM Unfall u
LEFT JOIN Versicherungsvertrag v ON u.vehicle_id = v.vehicle_id
WHERE (v.insurance_id IS NULL OR v.end_date < GETDATE())
  AND u.damage > 300;