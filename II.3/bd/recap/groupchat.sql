CREATE DATABASE "Group-Chat";

CREATE TABLE Benutzer (
    user_id INT PRIMARY KEY,
    username VARCHAR(10) UNIQUE NOT NULL,
    email VARCHAR(50) UNIQUE NOT NULL
);

CREATE TABLE Gruppe (
    group_id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    description TEXT
);

CREATE TABLE Members (
    user_id INT NOT NULL,
    group_id INT NOT NULL,
    PRIMARY KEY (user_id, group_id),
    CONSTRAINT fk_members_user_id FOREIGN KEY (user_id) REFERENCES Benutzer(user_id) ON DELETE CASCADE,
    CONSTRAINT fk_members_group_id FOREIGN KEY (group_id) REFERENCES Gruppe(group_id) ON DELETE CASCADE
);

CREATE TABLE Nachricht(
    message_id INT PRIMARY KEY,
    user_id INT NOT NULL,
    group_id INT NOT NULL,
    text varchar(100) NOT NULL,
    timestamp DATETIME NOT NULL,
    CONSTRAINT fk_nachricht_group_id FOREIGN KEY (group_id) REFERENCES Gruppe(group_id) ON DELETE CASCADE,
    CONSTRAINT fk_nachricht_user_id FOREIGN KEY (user_id) REFERENCES Benutzer(user_id) ON DELETE CASCADE
)

CREATE TABLE Anruf(
    call_id INT PRIMARY KEY,
    group_id INT NOT NULL,
    duration INT NOT NULL,
    participants INT NOT NULL,
    CONSTRAINT fk_anruf_group_id FOREIGN KEY (group_id) REFERENCES Gruppe(group_id) ON DELETE CASCADE
)

INSERT INTO Benutzer (user_id, username, email)
VALUES (1, 'alice', 'alice@example.com'),
       (2, 'bob', 'bob@example.com'),
       (3, 'charlie', 'charlie@example.com'),
       (4, 'malina', 'malina@example.com'),
       (5, 'alexia', 'alexia@example.com'),
       (6, 'janine', 'janine@example.com');

INSERT INTO Gruppe (group_id ,name, description)
VALUES (1, 'Revelion 2025', 'Petrecerea de Revelion'),
       (2, 'Silvester', 'Grup de discuții pentru Silvester');

INSERT INTO Members (user_id, group_id)
VALUES (1, 1), -- Alice în grupul "Revelion 2025"
       (2, 1), -- Bob în grupul "Revelion 2025"
       (1, 2), -- Alice în grupul "Silvester"
       (3, 2), -- Charlie în grupul "Silvester"
        (3,1),
        (4,1),
        (5,1),
        (6,1);

INSERT INTO Nachricht (message_id, group_id, user_id, Text, Timestamp)
VALUES (1, 1, 1, 'La mulți ani!', '2024-12-29 23:59:59'),
       (2, 1, 2, 'Mulțumesc!', '2024-12-29 00:01:00');

INSERT INTO Anruf (call_id, group_id, Duration, Participants)
VALUES (1, 1, 120, 5),
       (2, 2, 160, 7);

SELECT b.username -- what interests me?
FROM Benutzer b -- where can i get it from?
JOIN Members m ON b.user_id = m.user_id -- join on connection table
JOIN Gruppe g ON m.group_id = g.group_id -- join on the other side of the conncection table
WHERE g.Name = 'Revelion 2025' -- condition
  AND (
    SELECT COUNT(*) -- aggregation function; what interests me?
    FROM Nachricht n -- where can i get it from?
    WHERE n.user_id = b.user_id  -- join on foregin keys
      AND n.group_id = g.group_id --
      AND n.Timestamp > '2024-12-30' -- condition
  ) = 0; --

-- ALTERNATIVE
SELECT b.username
FROM Benutzer b
JOIN Members m ON b.user_id = m.user_id
JOIN Gruppe g ON m.group_id = g.group_id
LEFT JOIN Nachricht n ON n.user_id = b.user_id AND n.group_id = g.group_id AND n.Timestamp > '2024-12-30'
WHERE g.Name = 'Revelion 2025'
GROUP BY b.username -- having aggr. needs a group by field from select
HAVING COUNT(n.message_id) = 0;

SELECT g.Name AS 'Group Name',
       AVG(a.Participants) AS 'Avg no of participants',
       AVG(a.Duration) AS 'Avg Duration'
FROM Gruppe g
JOIN Members m ON g.group_id = m.group_id
JOIN Anruf a ON g.group_id = a.group_id
GROUP BY g.group_id, g.Name -- having aggr. needs a group by field from select
HAVING COUNT(m.user_id) > 3;