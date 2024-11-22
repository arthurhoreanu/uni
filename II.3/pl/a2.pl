%% Diese Datenbank gehört einem Musiklabel und enthält Informationen über Künstler,
%% ihre Manager, Alben, Mitarbeiter und Projekte.

% kunstler(KunstlerID, Name, Typ, Genre, Aktiv, Land, ManagerID)
kunstler(1, 'HIM', 'Band', 'Gothic Rock', 0, 'Finnland', 1).
kunstler(2, 'Poets of the Fall', 'Band', 'Alternative Rock', 1, 'Finnland', 1).
kunstler(3, 'Björk', 'Solo Künstler', 'Pop', 1, 'Island', 1).
kunstler(4, 'Dean Klooge', 'Band', 'Alternative Rock', 1, 'Rumänien', 2).
kunstler(5, 'Lady Gaga', 'Solo Künstler', 'Pop', 1, 'Vereinigte Staaten', 3).
kunstler(6, 'Tony Bennett', 'Solo Künstler', 'Jazz', 0, 'Vereinigte Staaten', 3).

% manager(ManagerID, Name)
manager(1, 'Thomas Lindskog').
manager(2, 'Alexandra Vulcan').
manager(3, 'Zoe Bailey').

% album(UPC, Titel, Veröffentlichungsdatum)
album(195999102701, 'Dark Light', 2005-09-26).
album(195999102702, 'Carnival of Rust', 2006-04-12).
album(195999102703, 'Homogenic', 1997-09-22).
album(195999102704, 'Cheek to Cheek', 2014-09-19).
album(195999102705, 'Love for Sale', 2021-09-30).

% kunstler_album(KunstlerID, UPC)
kunstler_album(1, 195999102701).
kunstler_album(2, 195999102702).
kunstler_album(3, 195999102703).
kunstler_album(5, 195999102704).
kunstler_album(6, 195999102704).
kunstler_album(5, 195999102705).
kunstler_album(6, 195999102705).

% mitarbeiter(MitarbeiterID, Name, Abteilung)
mitarbeiter(1, 'Josefine Fältskog', 'Marketing').
mitarbeiter(2, 'Hugo Hägglund', 'Produktion').
mitarbeiter(3, 'Matthew Ward', 'Marketing').
mitarbeiter(4, 'Kate James', 'Produktion').
mitarbeiter(5, 'Sonia Carter', 'Marketing').

% projekt(ProjektID, Titel, Startdatum, Enddatum)
projekt(1, 'Medienkampagne für das neue Album von Lady Gaga', 2024-09-01, 2024-12-31).
projekt(2, 'Björk Orkestral Tour', 2021-10-01, 2023-04-23).
projekt(3, 'Poets of the Fall Ghostlight Tour', 2022-01-01, 2023-12-12).

% mitarbeiter_projekt(MitarbeiterID, ProjektID)
mitarbeiter_projekt(1, 3).
mitarbeiter_projekt(2, 3).
mitarbeiter_projekt(5, 1).
mitarbeiter_projekt(4, 1).
mitarbeiter_projekt(3, 2).
mitarbeiter_projekt(2, 2).

% Beziehung: Manager-Künstler (one-to-many)
manager_kunstler(ManagerName, KunstlerName) :-
    manager(ManagerID, ManagerName),
    kunstler(_, KunstlerName, _, _, _, _, ManagerID).

% Beziehung: Künstler-Alben (many-to-many)
kunstler_album_beziehung(KunstlerName, AlbumTitel) :-
    kunstler(KunstlerID, KunstlerName, _, _, _, _, _),
    kunstler_album(KunstlerID, UPC),
    album(UPC, AlbumTitel, _).

% Beziehung: Mitarbeiter-Projekte (many-to-many)
mitarbeiter_projekt_beziehung(MitarbeiterName, ProjektTitel) :-
    mitarbeiter(MitarbeiterID, MitarbeiterName, _),
    mitarbeiter_projekt(MitarbeiterID, ProjektID),
    projekt(ProjektID, ProjektTitel, _, _).

% Findet ein Album anhand des Titels und gibt die UPC und das Veröffentlichungsdatum zurück
finde_album(Titel, UPC, Veroeffentlichungsdatum) :-
    album(UPC, Titel, Veroeffentlichungsdatum).

% Findet alle Künstler, die von einem bestimmten Manager betreut werden
finde_kunstler_nach_manager(ManagerName, KunstlerName) :-
    manager(ManagerID, ManagerName),
    kunstler(_, KunstlerName, _, _, _, _, ManagerID).

% Findet alle Alben, die einem bestimmten Künstler zugeordnet sind
finde_albums_nach_kunstler(KunstlerName, AlbumTitel) :-
    kunstler(KunstlerID, KunstlerName, _, _, _, _, _),
    kunstler_album(KunstlerID, UPC),
    album(UPC, AlbumTitel, _).

% Findet alle Mitarbeiter, die an einem bestimmten Projekt beteiligt sind
finde_mitarbeiter_nach_projekt(ProjektTitel, MitarbeiterName) :-
    projekt(ProjektID, ProjektTitel, _, _),
    mitarbeiter_projekt(MitarbeiterID, ProjektID),
    mitarbeiter(MitarbeiterID, MitarbeiterName, _).