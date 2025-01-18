create database Practic;

create table Benutzer ( -- 1:n Playlist
    benutzer_id int primary key,
    email varchar(50) unique not null,
    birthday DATE not null
);

create table Band ( -- 1:n Lied
    band_id int primary key,
    band_name varchar(50) unique not null,
    country varchar(50) unique not null
);

create table Lied ( -- n:1 Band
    lied_id int primary key,
    lied_name varchar(50) not null,
    album varchar(50),
    band_id int not null,
    duration TIME not null,
    genre varchar(50) not null,
    foreign key (band_id) REFERENCES Band(band_id)
);

create table Playlist ( -- n:1 Benutzer
    playlist_id int primary key,
    playlist_name varchar(50) not null,
    benutzer_id int not null,
    FOREIGN key (benutzer_id) REFERENCES Benutzer(benutzer_id)
);

CREATE table Tracks ( -- n:m between Playlists and Lied
    track_id int primary key,
    lied_id int,
    playlist_id int
    FOREIGN key (lied_id) REFERENCES Lied(lied_id),
    FOREIGN key (playlist_id) REFERENCES Playlist(playlist_id)
);

insert into Lied
VALUES
(1, 'Empire', 'Album', 1, '18:01', 'metal'),
(2, 'Lied2', 'Album', 1, '2:00', 'metal');

insert into Benutzer
VALUES
(1, 'email', '2002-12-12'),
(2, 'email2', '1999-12-12');

insert into Playlist
VALUES
(1, 'name1', 1),
(2, 'name2', 2);

insert into Tracks
VALUES
(1, 1, 1),
(2, 1, 2),
(3, 2, 1),
(4, 2, 2),
(5, 3, 1),
(6, 3, 2);

-- query 1
SELECT 
    b.band_name AS Artist,
    l.lied_name AS Song,
    l.duration AS Duration
FROM Band b
JOIN Lied l ON b.band_id = l.band_id
WHERE l.duration = (
    SELECT MAX(l2.duration)
    FROM Lied l2
    WHERE l2.band_id = l.band_id
);

-- query 2

SELECT 
    b.band_name AS Artist,
    COUNT(DISTINCT p.benutzer_id) AS "No. Users",
    CAST(DATEADD(SECOND, SUM(DATEDIFF(SECOND, 0, l.duration)), 0) AS TIME) AS "Total Duration"
FROM Band b
JOIN Lied l ON b.band_id = l.band_id
JOIN Tracks t ON l.lied_id = t.lied_id
JOIN Playlist p ON t.playlist_id = p.playlist_id
JOIN Benutzer be ON p.benutzer_id = be.benutzer_id
WHERE be.birthday <= DATEADD(YEAR, -18, GETDATE()) -- utilizatori majori
GROUP BY b.band_name;