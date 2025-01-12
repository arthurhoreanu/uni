-- 1.
CREATE DATABASE L5;
USE L5;

CREATE TABLE Ta (
    idA INT PRIMARY KEY,
    a2 INT UNIQUE,
    a3 INT
);

DROP TABLE Ta;

CREATE TABLE Tb (
    idB INT PRIMARY KEY,
    b2 INT,
    b3 INT
);

DROP TABLE Tb;

CREATE TABLE Tc (
    idC INT PRIMARY KEY,
    idA INT,
    idB INT,
    FOREIGN KEY (idA) REFERENCES Ta(idA),
    FOREIGN KEY (idB) REFERENCES Tb(idB)
);

DROP TABLE Tc;

CREATE OR ALTER PROCEDURE InsertData
AS
BEGIN
    DECLARE @i INT;
    SET @i = 1;

    -- Ta
    WHILE @i <= 10000
    BEGIN
        INSERT INTO Ta (idA, a2, a3)
        VALUES (@i, @i * 10, FLOOR(1 + RAND() * 1000)); -- MIN + (RAND() * (MAX - MIN))
        SET @i = @i + 1;
    END;

    SET @i = 1;

    -- Tb
    WHILE @i <= 3000
    BEGIN
        INSERT INTO Tb (idB, b2, b3)
        VALUES (@i, FLOOR(1 + RAND() * 5000), FLOOR(1 + RAND() * 5000));
        SET @i = @i + 1;
    END;

    SET @i = 1;

    -- Tc
    WHILE @i <= 30000
    BEGIN
        INSERT INTO Tc (idC, idA, idB)
        VALUES (@i, FLOOR(1 + RAND() * 10000), FLOOR(1 + RAND() * 3000));
        SET @i = @i + 1;
    END;
END;

EXEC InsertData;

SELECT COUNT(*) AS NumberOfElementsInTa FROM Ta;
SELECT COUNT(*) AS NumberOfElementsInTb FROM Tb;
SELECT COUNT(*) AS NumberOfElementsInTc FROM Tc;

SELECT * FROM Ta;
SELECT * FROM Tb;
SELECT * FROM Tc;

-- 2.

--- a.
sp_helpindex Ta;

---- Clustered Index Scan
SELECT *
FROM Ta
ORDER BY idA;

---- Clustered Index Seek
SELECT *
FROM Ta
WHERE idA = 100;

DROP INDEX UQ__Ta__3213A9FAD1481448 ON Ta;

CREATE NONCLUSTERED INDEX IX_Ta_a2 ON Ta(a2);

DROP INDEX IX_Ta_a2 ON Ta;

---- Nonclustered Index Scan
SELECT a2
FROM Ta
ORDER BY a2;

---- Nonclustered Index Seek
SELECT a2
FROM Ta
WHERE a2 = 2000;

--- b.
--- Key Lookup from non-clustered index
SELECT a2, a3
FROM Ta
WHERE a2 = 5000;

--- c.

-- Without non-clustered index
SELECT *
FROM Tb
WHERE b2 = 1000;

-- Create non-clustered index
CREATE NONCLUSTERED INDEX IX_Tb_b2
ON Tb(b2);

-- With non-clustered index
SELECT *
FROM Tb
WHERE b2 = 1000;

drop INDEX IX_Tb_b2
ON Tb;

--- d.

-- INNER JOIN between Tc and Ta
SELECT Tc.idC, Ta.a2
FROM Tc
INNER JOIN Ta ON Tc.idA = Ta.idA
WHERE Tc.idA = 1000;

-- INNER JOIN between Tc and Tb
SELECT Tc.idC, Tb.b2
FROM Tc
INNER JOIN Tb ON Tc.idB = Tb.idB
WHERE Tc.idB = 500;

CREATE NONCLUSTERED INDEX IX_Tc_idA
ON Tc(idA);

DROP INDEX IX_Tc_idA ON Tc;

CREATE NONCLUSTERED INDEX IX_Tc_idB
ON Tc(idB);

DROP INDEX IX_Tc_idB ON Tc;

SELECT Tc.idC, Ta.a2
FROM Tc
INNER JOIN Ta ON Tc.idA = Ta.idA
WHERE Tc.idA = 1000;

SELECT Tc.idC, Tb.b2
FROM Tc
INNER JOIN Tb ON Tc.idB = Tb.idB
WHERE Tc.idB = 500;