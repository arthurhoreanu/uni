-- 1.

CREATE OR ALTER FUNCTION dbo.IsAdult (@BirthDate DATE)
RETURNS BIT
AS
BEGIN
    RETURN CASE
        WHEN DATEDIFF(YEAR, @BirthDate, GETDATE()) >= 18 THEN 1
        ELSE 0
    END
END;

CREATE OR ALTER FUNCTION dbo.IsNameValid (@Name NVARCHAR(50))
RETURNS BIT
AS
BEGIN
    RETURN CASE
        WHEN @Name LIKE '%[^a-zA-Z ]%' THEN 0 -- Checks for invalid characters
        ELSE 1
    END
END;

CREATE OR ALTER FUNCTION dbo.IsEmailValid (@Email NVARCHAR(50))
RETURNS BIT
AS
BEGIN
    RETURN CASE
        WHEN @Email LIKE '%@%.%' THEN 1 -- Basic check for "@" and "." in the email
        ELSE 0
    END
END;

CREATE OR ALTER PROCEDURE dbo.InsertEmployee
    @EmployeeID NVARCHAR(10),
    @FirstName NVARCHAR(50),
    @LastName NVARCHAR(50),
    @Email NVARCHAR(50),
    @Phone NVARCHAR(50),
    @BirthDate DATE,
    @Address NVARCHAR(50),
    @Position NVARCHAR(50),
    @Department NVARCHAR(50),
    @HQID NVARCHAR(10)
AS
BEGIN
    -- Validate FirstName
    IF dbo.IsNameValid(@FirstName) = 0
    BEGIN
        THROW 50001, 'FirstName must contain only alphabetic characters.', 1;
    END

    -- Validate LastName
    IF dbo.IsNameValid(@LastName) = 0
    BEGIN
        THROW 50002, 'LastName must contain only alphabetic characters.', 1;
    END

    -- Validate Email
    IF dbo.IsEmailValid(@Email) = 0
    BEGIN
        THROW 50003, 'Email format is invalid.', 1;
    END

    -- Validate BirthDate (Adult Check)
    IF dbo.IsAdult(@BirthDate) = 0
    BEGIN
        THROW 50004, 'Employee must be at least 18 years old.', 1;
    END

    -- Insert Employee
    INSERT INTO dbo.Employees (EmployeeID, FirstName, LastName, Email, Phone, BirthDate, Address, Position, Department, HQID)
    VALUES (@EmployeeID, @FirstName, @LastName, @Email, @Phone, @BirthDate, @Address, @Position, @Department, @HQID);
END;

EXEC InsertEmployee 
    'E001', 
    'John', 
    'Doe', 
    'john.doe@example.com', 
    '1234567890', 
    '1990-01-01', 
    '123 Main St', 
    'Manager', 
    'HR', 
    'HQSE';

DELETE FROM Employees WHERE EmployeeID='E001';

--2.

CREATE OR ALTER VIEW dbo.SongsByExplicitFlag
AS
SELECT 
    t.ISRC,
    t.Title,
    t.Duration,
    t.Explicit,
    ROW_NUMBER() OVER (PARTITION BY t.Explicit ORDER BY t.Title) AS RowNumber
FROM dbo.Tracks t;
GO

CREATE OR ALTER FUNCTION dbo.ArtistSongStats()
RETURNS TABLE
AS
RETURN
(
    SELECT 
        ar.Artist,                 
        a.Name AS ArtistName,        
        COUNT(t.ISRC) AS TotalSongs, 
        AVG(DATEDIFF(SECOND, '00:00:00', t.Duration)) AS AverageSongDurationInSeconds 
    FROM dbo.Artists a
    JOIN dbo.ArtistsRecords ar ON a.ArtistID = ar.Artist
    JOIN dbo.RecordTracks rt ON ar.UPCCode = rt.UPC
    JOIN dbo.Tracks t ON rt.ISRC = t.ISRC
    GROUP BY ar.Artist, a.Name
);
GO

SELECT 
    s.ISRC,
    s.Title,
    s.Explicit,
    ast.ArtistName,
    ast.TotalSongs,
    DATEADD(SECOND, ast.AverageSongDurationInSeconds, '00:00:00') AS AverageSongDuration
FROM dbo.SongsByExplicitFlag s
JOIN dbo.ArtistSongStats() ast
    ON s.ISRC IN (
        SELECT rt.ISRC 
        FROM dbo.RecordTracks rt
        JOIN dbo.ArtistsRecords ar ON rt.UPC = ar.UPCCode
        WHERE ar.Artist = ast.Artist
    )
ORDER BY ast.TotalSongs DESC;

--3.

DROP TABLE OperationLogs;

CREATE TABLE dbo.OperationLogs (
    LogID INT IDENTITY PRIMARY KEY,
    OperationDateTime DATETIME NOT NULL,
    OperationType NVARCHAR(10) NOT NULL, -- INSERT/UPDATE/DELETE
    TableName NVARCHAR(50) NOT NULL,
    AffectedRows INT NOT NULL
);
GO

CREATE OR ALTER TRIGGER trg_LogEmployeeChanges
ON dbo.Employees
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @Operation NVARCHAR(10);
    DECLARE @AffectedRows INT;

    -- Determine the type of operation
    IF EXISTS (SELECT 1 FROM inserted) AND EXISTS (SELECT 1 FROM deleted)
    BEGIN
        SET @Operation = 'UPDATE';
        SET @AffectedRows = (SELECT COUNT(*) FROM inserted);
    END
    ELSE IF EXISTS (SELECT 1 FROM inserted)
    BEGIN
        SET @Operation = 'INSERT';
        SET @AffectedRows = (SELECT COUNT(*) FROM inserted);
    END
    ELSE IF EXISTS (SELECT 1 FROM deleted)
    BEGIN
        SET @Operation = 'DELETE';
        SET @AffectedRows = (SELECT COUNT(*) FROM deleted);
    END

    -- Log the operation details
    INSERT INTO dbo.OperationLogs (OperationDateTime, OperationType, TableName, AffectedRows)
    VALUES (GETDATE(), @Operation, 'Employees', @AffectedRows);
END;
GO

INSERT INTO dbo.Employees (EmployeeID, FirstName, LastName, Email, Phone, BirthDate, Address, Position, Department, HQID)
VALUES 
('E0020', 'Alice', 'Smith', 'alice.smith@example.com', '9876543210', '1992-03-10', '456 Elm St', 'Designer', 'Marketing', 'HQSE'),
('E0021', 'Bob', 'Johnson', 'bob.johnson@example.com', '4561237890', '1988-07-22', '789 Oak St', 'Manager', 'Sales', 'HQSE');
GO

UPDATE Employees
SET Email='new.alice.smith@example.com'
WHERE EmployeeID='E0020';
GO

DELETE FROM dbo.Employees
WHERE EmployeeID IN ('E0020', 'E0021');
GO

SELECT * FROM OperationLogs;
GO

-- 4.

drop table ExpirationAlerts;

CREATE TABLE dbo.ExpirationAlerts (
    AlertID INT IDENTITY PRIMARY KEY,
    LicenseID NVARCHAR(10),
    AlertDate DATETIME,
    DaysUntilExpiration INT
);
GO

CREATE OR ALTER PROCEDURE GenerateExpirationAlert
    @LicenseID NVARCHAR(10),
    @DaysUntilExpiration INT
AS
BEGIN
    INSERT INTO dbo.ExpirationAlerts (LicenseID, AlertDate, DaysUntilExpiration)
    VALUES (@LicenseID, GETDATE(), @DaysUntilExpiration);
END;
GO

CREATE OR ALTER PROCEDURE ProcessLicensesForExpirationAlerts
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @LicenseID NVARCHAR(10);
    DECLARE @ExpirationDate DATETIME;
    DECLARE @DaysUntilExpiration INT;

    -- Cursor to iterate over all licenses
    DECLARE license_cursor CURSOR FOR
    SELECT LicenseID, ExpirationDate
    FROM dbo.ProductLicenses;

    OPEN license_cursor;

    FETCH NEXT FROM license_cursor INTO @LicenseID, @ExpirationDate;
    WHILE @@FETCH_STATUS = 0
    BEGIN
        -- Calculate days until expiration
        SET @DaysUntilExpiration = DATEDIFF(DAY, GETDATE(), @ExpirationDate);

        -- If within the 30-day threshold, generate an alert
        IF @DaysUntilExpiration > 0 AND @DaysUntilExpiration <= 30
        BEGIN
            EXEC GenerateExpirationAlert @LicenseID, @DaysUntilExpiration;
        END;

        FETCH NEXT FROM license_cursor INTO @LicenseID, @ExpirationDate;
    END;

    CLOSE license_cursor;
    DEALLOCATE license_cursor;
END;
GO

INSERT INTO dbo.ProductLicenses (LicenseID, ISRC, Purpose, StartDate, ExpirationDate)
VALUES 
('LIC001', 'usx9p2053108', 'Music License', '2024-01-01', DATEADD(DAY, 15, GETDATE())), -- Expires in 15 days
('LIC001', 'usx9p2053108', 'Video License', '2024-01-01', DATEADD(DAY, 45, GETDATE())), -- Expires in 45 days
('LIC001', 'usx9p2053108', 'Broadcast License', '2024-01-01', DATEADD(DAY, 5, GETDATE())); -- Expires in 5 days
GO

delete from ProductLicenses
where LicenseID='LIC001';

EXEC ProcessLicensesForExpirationAlerts;
GO

SELECT * 
FROM dbo.ExpirationAlerts;
GO