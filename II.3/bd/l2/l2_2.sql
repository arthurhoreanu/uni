-- 1.  UNION +  1/7 JOIN + 1/5 WHERE + 1/3 GROUP BY + 1/2 HAVING + 1/3 AGG
-- Managers + active Bands (Artists with more than 1 promisor)
SELECT ManagerID as ID, Name, 'Manager' as Type
FROM dbo.Managers
UNION
SELECT DISTINCT a.ArtistID, a.Name, 'Artist'
FROM dbo.Artists a
INNER JOIN dbo.ArtistsRecords ar ON a.ArtistID = ar.Artist
INNER JOIN dbo.Records r ON ar.UPCCode = r.UPC
INNER JOIN dbo.PromisorsArtists pa ON pa.IDArtist = a.ArtistID
WHERE pa.IDArtist =  a.ArtistID 
GROUP BY a.ArtistID, a.Name
HAVING COUNT(DISTINCT pa.PromisorID) > 1;

-- 2. 2/7 JOIN + 2/5 WHERE + IN
-- Employees from Production&Marketing currently working on Projects
SELECT e.EmployeeID, e.FirstName, e.LastName, h.HQID, e.Department, p.Name AS ProjectName
FROM dbo.Employees e
INNER JOIN dbo.Employment emp ON e.EmployeeID = emp.EmployeeID
INNER JOIN dbo.Projects p ON emp.ProjectID = p.ProjectID
INNER JOIN dbo.Headquarters h ON e.HQID = h.HQID
WHERE e.Department IN ('Production', 'Marketing')
AND p.EndDate > GETDATE();

-- 3. OUTER JOIN + 3/5 WHERE
-- All Projects from 2024 onwards, no matter if Employee was assigned or not
SELECT 
    p.Name AS ProjectName, 
    p.StartDate,
    e.FirstName + ' ' + e.LastName AS EmployeeName
FROM 
    dbo.Projects p
LEFT OUTER JOIN 
    dbo.Employment emp ON p.ProjectID = emp.ProjectID
LEFT OUTER JOIN 
    dbo.Employees e ON emp.EmployeeID = e.EmployeeID
WHERE 
    p.StartDate >= '2024-01-01';

-- 4. DISTINCT + 3/7 JOIN + 4/5 WHERE + 1/3 GROUP BY + 1/2 HAVING + 2/3 AGG + NOT IN
-- Headquarters with more than 2 Employees minus Interns
SELECT DISTINCT
    h.Location as HeadquartersLocation,
    e.Department,
    e.Position
FROM dbo.Employees e
INNER JOIN  dbo.Headquarters h ON e.HQID = h.HQID
INNER JOIN  dbo.Employment emp ON e.EmployeeID = emp.EmployeeID
INNER JOIN  dbo.Projects p ON emp.ProjectID = p.ProjectID
WHERE e.Department IN (
    SELECT Department
    FROM dbo.Employees
    GROUP BY Department
    HAVING COUNT(*) > 2
)
AND e.EmployeeID NOT IN (
    SELECT e2.EmployeeID
    FROM dbo.Employees e2
    WHERE e2.Position = 'Intern'
);

-- 5. TOP + 4/7 JOIN + 5/5 WHERE + 2/3 GROUP BY + ORDER BY
-- Top 5 Employees Project-wise from the Sweden HQ
SELECT TOP 5 
    e.FirstName + ' ' + e.LastName as EmployeeName,
    e.Department,
    COUNT(emp.ProjectID) as ProjectCount,
    h.HQID
FROM dbo.Employees e
INNER JOIN dbo.Employment emp ON e.EmployeeID = emp.EmployeeID
INNER JOIN dbo.Projects p ON emp.ProjectID = p.ProjectID
INNER JOIN dbo.Headquarters h ON e.HQID = h.HQID
WHERE h.HQID = 'HQSE'
GROUP BY e.EmployeeID, e.FirstName, e.LastName, e.Department, h.HQID
ORDER BY ProjectCount DESC;

-- 6. 5/7 JOIN + 3/3 GROUP BY + 2/2 HAVING + 3/3 AGG 
-- Bands and their Promisors
SELECT
    a.Name as ArtistName,
    COUNT(DISTINCT pa.PromisorID) as PromisorCount,
    STRING_AGG(p.Name, ', ') as Promisors
FROM dbo.Artists a
INNER JOIN dbo.PromisorsArtists pa ON a.ArtistID = pa.IDArtist
INNER JOIN dbo.Promisors p ON pa.PromisorID = p.PromisorID
INNER JOIN dbo.Managers m ON a.IDManager = m.ManagerID
WHERE a.Active = 1
GROUP BY a.ArtistID, a.Name
HAVING COUNT(DISTINCT pa.PromisorID) > 1;

-- 7. ANY + OR
-- Employees who started working on a project on 2024-01-0 or 2025-01-01
SELECT e.FirstName, e.LastName, e.HQID
FROM dbo.Employees e
WHERE e.EmployeeID = ANY (SELECT emp.EmployeeID
                          FROM dbo.Employment emp
                          INNER JOIN dbo.Projects p ON emp.ProjectID = p.ProjectID
                          INNER JOIN dbo.Headquarters h ON e.HQID = h.HQID
                          WHERE p.StartDate = '2024-01-01' OR p.StartDate = '2025-01-01');

-- 8. EXCEPT
-- All employees except employees from the Production department
SELECT DISTINCT e.EmployeeID, e.FirstName, e.LastName
FROM dbo.Employees e
EXCEPT
SELECT e.EmployeeID, e.FirstName, e.LastName
FROM dbo.Employees e
INNER JOIN dbo.Employment emp ON e.EmployeeID = emp.EmployeeID
INNER JOIN dbo.Projects p ON emp.ProjectID = p.ProjectID
WHERE e.Department = 'Production';

-- 9. INTERSECT + 6/7 JOIN
-- Employees from the Stockholm HQ currently working on Projects
SELECT e.EmployeeID, e.FirstName, e.LastName, e.HQID
FROM dbo.Employees e
INNER JOIN dbo.Employment emp ON e.EmployeeID = emp.EmployeeID
INNER JOIN dbo.Projects p ON emp.ProjectID = p.ProjectID
WHERE p.EndDate > GETDATE()
INTERSECT
SELECT e.EmployeeID, e.FirstName, e.LastName, e.HQID
FROM dbo.Employees e
INNER JOIN dbo.Employment emp ON e.EmployeeID = emp.EmployeeID
INNER JOIN dbo.Projects p ON emp.ProjectID = p.ProjectID
INNER JOIN dbo.Headquarters h ON e.HQID = h.HQID
WHERE h.Location = 'Stockholm';

-- 10. 7/7 JOIN + ALL
-- All employees from the NY HQ
SELECT e.EmployeeID, e.FirstName, e.LastName, h.HQID
FROM dbo.Employees e
INNER JOIN dbo.Employment emp ON e.EmployeeID = emp.EmployeeID
INNER JOIN dbo.Projects p ON emp.ProjectID = p.ProjectID
INNER JOIN dbo.Headquarters h ON e.HQID = h.HQID
WHERE h.HQID = 'HQNY'
  AND emp.ProjectID = ALL (
      SELECT p2.ProjectID
      FROM dbo.Projects p2
      INNER JOIN dbo.Employment emp2 ON p2.ProjectID = emp2.ProjectID
      INNER JOIN dbo.Employees e2 ON emp2.EmployeeID = e2.EmployeeID
      WHERE e2.HQID = h.HQID
  );