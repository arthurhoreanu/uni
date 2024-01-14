# 1.
# Geben Sie eine Textdatei mit dem Namen 'text.txt' an, die in jeder Zeile den Vor- und Nachnamen des Schülers,
# das Fach und die jeweilige Note enthält. Die Felder sollen durch drei Strichpunkt (';;;') voneinander getrennt sein.
# Schreiben Sie eine Funktion namens 'ub1', die folgendes tut:
#  - liest aus der angegebenen Datei 'text.txt'
#  - behält nur die Zeilen, bei denen der Nachname eine Länge von 3 hat und die Note eine gerade Zahl ist (0,5 Punkte)
#  - gibt einen String aller Fächer aus den behaltenen Zeilen zurück. Die Fächer sollen in Kleinbuchstaben und durch
#    Kommas getrennt sein. (0,5 Punkte)
# Die Verwendung von for- oder while-Schleifen, list comprehension ist nicht erlaubt. Es wird erwartet,
# dass die Lösung map, filter, reduce und andere mathematische Operationen, falls erforderlich, verwendet. (2 Punkte)
#
# b. Schreiben Sie für die Funktion "ub1" zwei Testfälle. (1p)
# Einer, der das erwartete Ergebnis der Funktion bestätigt und ein anderer, der absichtlich fehlschlägt.

from functools import reduce

def ub1():
    # Funktion zum Filtern von Zeilen
    def filter_lines(line):
        parts = line.split(";;;")
        last_name = parts[1].strip()
        grade = int(parts[3].strip())
        return len(last_name) == 3 and grade % 2 == 0

    # Funktion zum Extrahieren von Fächern
    def extract_subject(line):
        return line.split(";;;")[2].strip().lower()

    # Funktion zum Zusammenführen von Fächern
    def combine_subjects(subjects, subject):
        if subjects:
            return subjects + ", " + subject
        else:
            return subject

    # Datei lesen und Zeilen filtern
    with open('text.txt', 'r') as file:
        lines = file.readlines()
        filtered_lines = filter(filter_lines, lines)

    # Fächer extrahieren und kombinieren
    subjects = reduce(combine_subjects, map(extract_subject, filtered_lines), '')

    return subjects

# Testfall 1: Funktion mit erwartetem Ergebnis
result1 = ub1()
expected_result1 = "mathematik, deutsch"
assert result1 == expected_result1, f"Erwartet: {expected_result1}, erhalten: {result1}"

# Testfall 2: Funktion mit absichtlichem Fehler
# In diesem Beispiel gibt es einen absichtlichen Fehler in der Eingabedatei,
# sodass die Funktion ein unerwartetes Ergebnis liefern sollte.
with open('text.txt', 'a') as file:
    file.write("Max Mustermann;;;MMM;;;5,5\n")

result2 = ub1()
expected_result2 = "mathematik, deutsch"  # Falsches erwartetes Ergebnis
assert result2 == expected_result2, f"Erwartet: {expected_result2}, erhalten: {result2}"

# 2.
# a. Schreiben Sie die Definition für eine Klasse namens "Student". Die Klasse sollte in der Lage sein,
# Folgendes zu tun:
# - Bei der Initialisierung wird die Instanzvariable "grades" auf einen gegebenen Parameter gesetzt.
# - Der Typ des Parameters ist eine Liste von Zahlen. (0,5 Punkte)
# - Eine Methode namens "take_exam" haben, die:
#   - Einen einzelnen String-Parameter namens "exam" bekommt
#   - Für alle Elemente aus der Liste "grades" prüft, ob alle größer oder gleich 5 sind (0,5 Punkte)
#   - Eine neue Liste zurückgibt, die nur ein Element enthält, und zwar ein Tuple, gebildet aus dem Parameter "exam"
#     und dem ersten Element der Liste "grades" (0,5 Punkte)
#   - Eine benutzerdefinierte Ausnahme namens "FailedExam" wirft, wenn kein Element größer oder gleich 5 ist(0,5 Punkte)

# b. Schreiben Sie die Definition für eine Klasse namens "ComputerScienceStudent", die von "Student" erbt.
# Die Klasse sollte Folgendes können:
# - Bei der Initialisierung setzt sie neben den Variablen von "Book" auch eine Instanzvariable namens "laptop" auf ein
#   leeres Wörterbuch (dict). (0,25 Punkte)
# - Überschreiben der Methode "take_exam", um Folgendes zu tun:
#   - Wiederverwendung der Methode "take_exam" aus der Basisklasse (0,25 Punkte)
#   - Im Falle eines erfolgreichen Aufrufs wird das Ergebnis in der Instanzvariable "laptop" gespeichert, wobei der
#     Schlüssel und der Wert das erste beziehungsweise zweite Element des Tupels sind (0,25 Punkte)
#   - Im Falle eines fehlgeschlagenen Aufrufs wird in der Instanzvariable "laptop" ein Eintrag hinzugefügt, wobei der
#     Schlüssel der Parameter "exam" ist und der Wert 0 ist (0,25 Punkte)
# - Das Ergebnis der Addition zwischen zwei Instanzen des Typs "ComputerScienceStudent" (stud1 + stud2) ist ein
#   Wörterbuch, das alle Einträge der beiden "laptop"-Instanzvariablen enthält.
#   Die Priorität der Einträge ist nicht wichtig. (1 Punkt)

class FailedExam(Exception):
    pass

class Student:
    def __init__(self, grades):
        self.grades = grades

    def take_exam(self, exam):
        if all(grade >= 5 for grade in self.grades):
            result = [(exam, self.grades[0])]
            return result
        else:
            raise FailedExam("Student failed the exam")

class ComputerScienceStudent(Student):
    def __init__(self, grades):
        super().__init__(grades)
        self.laptop = {}

    def take_exam(self, exam):
        try:
            result = super().take_exam(exam)
            self.laptop[exam] = result[0][1]
        except FailedExam:
            self.laptop[exam] = 0

    def __add__(self, other):
        combined_laptops = {**self.laptop, **other.laptop}
        return combined_laptops

# Beispielverwendung:
# student1 = ComputerScienceStudent([6, 7, 8])
# student2 = ComputerScienceStudent([4, 5, 6])
# student1.take_exam("Python")
# student2.take_exam("Java")
# combined_laptops = student1 + student2
# print(combined_laptops)

# 3. Schreibe die folgende Funktion so um, dass sie rekursiv ist: (1p)
def my_func(n):
    lst = []
    total = 0
    for i in range(-n, n):
        if i % 10 == 0:
            total += i
        lst.append(total)
    return lst

def my_func_recursive(n, i=-n, total=0, lst=None):
    if lst is None:
        lst = []

    if i < n:
        if i % 10 == 0:
            total += i
        lst.append(total)
        return my_func_recursive(n, i + 1, total, lst)
    else:
        return lst

# Beispielaufruf
result = my_func_recursive(10)
print(result)