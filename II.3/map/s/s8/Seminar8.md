# Seminar 8

## Build Management Systemen

In der Java-Entwicklung spielen Build-Systeme eine entscheidende Rolle bei der Automatisierung von Build-Prozessen, der Verwaltung von Abhängigkeiten und der Erstellung von Artefakten. Eines der modernsten und flexibelsten Build-Systeme ist Gradle. Im Gegensatz zu traditionellen Build-Tools wie Maven nutzt Gradle eine domänenspezifische Sprache (DSL) basierend auf Groovy oder Kotlin, was es Entwicklern ermöglicht, Build-Skripte in einer deklarativen und leicht verständlichen Weise zu schreiben. Diese Flexibilität ermöglicht es, komplexe Build-Prozesse zu definieren und anzupassen, ohne sich in festgelegten Strukturen zu verlieren.

Ein weiterer Vorteil von Gradle ist seine hohe Leistungsfähigkeit. Durch die Verwendung von inkrementellen Builds und der intelligenten Abhängigkeitsanalyse kann Gradle Build-Zeiten erheblich reduzieren, insbesondere bei großen Projekten. Zudem unterstützt Gradle eine breite Palette von Plugins, die es ermöglichen, nahezu jeden Aspekt des Build-Prozesses anzupassen, sei es das Kompilieren von Code, das Erstellen von JAR-Dateien oder das Einrichten von Continuous Integration.

Trotz der Vorteile von Gradle bleibt Maven ein weit verbreitetes Build-System in der Java-Welt. Maven verfolgt einen deklarativen Ansatz und basiert auf dem Konzept der "Konvention über Konfiguration", was bedeutet, dass es eine Standardstruktur für Projekte vorgibt, die viele Entwickler als einfacher und intuitiver empfinden. Maven ist besonders nützlich für Projekte, die eine klare und stabile Build-Struktur benötigen, und bietet eine umfangreiche Unterstützung für die Verwaltung von Abhängigkeiten über das Central Repository. Obwohl Gradle in vielen Aspekten überlegen ist, bleibt Maven aufgrund seiner Einfachheit und Stabilität eine gute Wahl für viele Java-Projekte.

## Problem 1

Sie sollen eine Java-Anwendung entwickeln, die die Verwendung von JDBC (Java Database Connectivity)
zur Interaktion mit einer MySQL-Datenbank demonstriert. 
Die Anwendung soll es Benutzern ermöglichen, grundlegende CRUD-Operationen (Create, Read, Update, Delete) 
auf einer Datenbanktabelle durchzuführen. 
Die Tabelle soll Informationen über Bücher speichern, einschließlich Attributen wie Titel, Autor, ISBN und Erscheinungsjahr.
```sql
CREATE TABLE books (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    author VARCHAR(255) NOT NULL,
    isbn VARCHAR(13) NOT NULL,
    publication_year INT
);
```
Die Anwendung soll eine einfache Kommandozeilenschnittstelle (CLI) bereitstellen, in der Benutzer Befehle eingeben können:
* um neue Bücher hinzuzufügen
* bestehende Bücher anzuzeigen
* Buchdetails zu aktualisieren
* Bücher aus der Datenbank zu löschen. 

Darüber hinaus soll die Anwendung potenzielle Fehler, wie Datenbankverbindungsprobleme oder ungültige Benutzereingaben, angemessen behandeln.

## Problem 2

Setzen Sie die Anwendung aus Seminar 5 fort und implementieren Sie ein DBRepository.