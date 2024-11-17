CREATE TABLE Licenses (
    LicenseID VARCHAR (10) NOT NULL PRIMARY KEY,
    Type     VARCHAR (50) NOT NULL
);

CREATE TABLE ProductLicenses (
    LicenseID VARCHAR (10),
    ISRC CHAR (20)   ,
    Purpose VARCHAR (50) NOT NULL,
    StartDate DATETIME NOT NULL,
    ExpirationDate DATETIME NOT NULL,
    PRIMARY KEY (LicenseID, ISRC),
    CONSTRAINT FK_ProductLicenses FOREIGN KEY (LicenseID) REFERENCES Licenses,
    FOREIGN KEY (ISRC) REFERENCES Tracks
);

INSERT INTO Artists (ArtistID, Name, Type, Genre, Active, Country, IDManager)
VALUES ('UK85959592', 'Depeche Mode', 'Band', 'Synth-pop', 1, 'United Kingdom', '10003'),
       ('RO85959534', 'Dean Klooge', 'Band', 'Alternative rock', 1, 'Romania', '10002');

INSERT INTO Licenses (LicenseID, Type)
VALUES ('LIC001', 'Synchronization License'),
    ('LIC002', 'Mechanical License'),
    ('LIC003', 'Public Performance License');

INSERT INTO ProductLicenses (LicenseID, ISRC, Purpose, StartDate, ExpirationDate)
VALUES('LIC001', 'usx9p2053101', 'Vodafone commercial', 2024-01-01, 2025-01-01);

INSERT INTO ProductLicenses (LicenseID, ISRC, Purpose, StartDate, ExpirationDate)
VALUES('LIC007', 'usx9p2053101', 'Orange commercial', 2024-01-01, 2025-01-01);

UPDATE Artists
SET Artists.Type = 'Ex-Solo Artist'
WHERE Artists.Type = 'Solo Artist' AND Artists.IDManager IS NOT NULL;


DELETE FROM Projects
WHERE Projects.ProjectID IN ('PR10001', 'PR10002', 'PR10004') AND Projects.StartDate BETWEEN '2023-09-26' AND '2025-09-28' AND Projects.Name LIKE '%O%';
