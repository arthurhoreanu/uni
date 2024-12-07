# Unit-Testing in Java

Unit-Testing ist eine grundlegende Praxis in der Softwareentwicklung, die das Testen einzelner Einheiten oder Komponenten
einer Softwareanwendung zum Zweck der Überprüfung ihrer korrekten Funktionsweise beinhaltet. In Java wird das Unit-Testing
typischerweise mit Test-Frameworks wie JUnit durchgeführt. Das Ziel des Unit-Testings ist es, sicherzustellen, dass jeder
Teil des Codes in Isolation korrekt funktioniert, was hilft, Fehler früh im Entwicklungsprozess zu identifizieren und zu
beheben.

## Schlüsselbegriffe im Unit-Testing

**Testfälle**: Ein Testfall ist eine Menge von Bedingungen oder Variablen, unter denen ein Tester bestimmt, ob eine Anwendung
ordnungsgemäß funktioniert.

**Testmethoden**: Diese sind individuelle Methoden innerhalb einer Testklasse, die Assertions enthalten, um das Verhalten des
getesteten Codes zu überprüfen.

**Assertions**: Assertions sind Überprüfungen, die prüfen, ob die Ausgabe einer Methode mit dem erwarteten Ergebnis
übereinstimmt. JUnit-Assertions sind `assertEquals()`, `assertTrue()` und `assertNull()`.

**Test-Suites**: Eine Test-Suite ist eine Sammlung von Testfällen, die zusammen ausgeführt werden können.

**Setup und Teardown**: Diese sind Methoden, die vor und nach jeder Testmethode ausgeführt werden, um die notwendigen
Bedingungen herzustellen oder Ressourcen zu bereinigen.

## Best Practices im Unit-Testing

**Tests unabhängig halten**: Jeder Test sollte unabhängig von anderen sein, was bedeutet, dass das Ergebnis eines Tests das
andere nicht beeinflussen sollte.

**Nur ein Aspekt pro Test überprüfen**: Jede Testmethode sollte sich auf die Überprüfung eines spezifischen Aspekts des Codes
konzentrieren.

**Mittelbare Testnamen verwenden**: Testnamen sollten klar beschreiben, was getestet wird.

**Randfälle abdecken**: Stellen Sie sicher, dass Ihre Tests Randfälle und Grenzbedingungen abdecken.

## Übungen

### Übung 1: Testen einer einfachen Rechner-Klasse

#### Klasse, die getestet werden soll: `Calculator`

```java
public class Calculator {
    public int add(int a, int b) {
        return a + b;
    }

    public int subtract(int a, int b) {
        return a - b;
    }

    public int multiply(int a, int b) {
        return a * b;
    }

    public int divide(int a, int b) {
        if (b == 0) {
            throw new ArithmeticException("Division durch Null");
        }
        return a / b;
    }
}
```

#### Übung: Schreiben Sie JUnit-Tests für die `Calculator`-Klasse.

* Testen Sie die `add`-Methode mit positiven Zahlen, negativen Zahlen und Null.
* Testen Sie die `subtract`-Methode mit positiven Zahlen, negativen Zahlen und Null.
* Testen Sie die `multiply`-Methode mit positiven Zahlen, negativen Zahlen und Null.
* Testen Sie die `divide`-Methode mit positiven Zahlen, negativen Zahlen und testen Sie die Ausnahme bei Division durch Null.

### Übung 2: Testen einer String-Utility-Klasse

#### Klasse, die getestet werden soll: `StringUtils`

```java
public class StringUtils {
    public static boolean isEmpty(String str) {
        return str == null || str.trim().isEmpty();
    }

    public static String truncate(String str, int length) {
        if (str == null) {
            throw new IllegalArgumentException("String darf nicht null sein");
        }
        if (length < 0) {
            throw new IllegalArgumentException("Länge darf nicht negativ sein");
        }
        if (str.length() <= length) {
            return str;
        }
        return str.substring(0, length);
    }
}
```

#### Übung: Schreiben Sie JUnit-Tests für die `StringUtils`-Klasse.

* Testen Sie die `isEmpty`-Methode mit null, leerem String, Leerzeichen und nicht-leeren Strings.
* Testen Sie die `truncate`-Methode mit Strings verschiedener Längen, einschließlich Fällen, in denen der String kürzer ist
  als die angegebene Länge, und testen Sie die Ausnahmen für ungültige Eingaben.

### Übung 3: Testen einer Bank-Kontoklasse

#### Klasse, die getestet werden soll: `BankAccount`

```java
public class BankAccount {
    private double balance;

    public BankAccount(double initialBalance) {
        if (initialBalance < 0) {
            throw new IllegalArgumentException("Anfangsbetrag darf nicht negativ sein");
        }
        this.balance = initialBalance;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Der Einzahlungsbetrag muss positiv sein");
        }
        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Der Auszahlungsbetrag muss positiv sein");
        }
        if (balance < amount) {
            throw new IllegalArgumentException("Unzureichender Kontostand");
        }
        balance -= amount;
    }
}
```

#### Übung: Schreiben Sie JUnit-Tests für die `BankAccount`-Klasse.

* Testen Sie den Konstruktor mit positivem, null und negativem Anfangsbetrag.
* Testen Sie die `deposit`-Methode mit positiven Beträgen und testen Sie die Ausnahme für nicht positive Beträge.
* Testen Sie die `withdraw`-Methode mit positiven Beträgen, unzureichendem Kontostand und testen Sie die Ausnahme für nicht
  positive Beträge.

### Übung 4: Testen einer benutzerdefinierten List-Klasse

#### Klasse, die getestet werden soll: `CustomList`

```java
import java.util.ArrayList;
import java.util.List;

public class CustomList<T> {
    private List<T> list = new ArrayList<>();

    public void add(T element) {
        list.add(element);
    }

    public T get(int index) {
        if (index < 0 || index >= list.size()) {
            throw new IndexOutOfBoundsException("Index außerhalb des Bereichs");
        }
        return list.get(index);
    }

    public int size() {
        return list.size();
    }
}
```

#### Übung: Schreiben Sie JUnit-Tests für die `CustomList`-Klasse.

* Testen Sie die `add`-Methode, indem Sie Elemente hinzufügen und die Größe überprüfen.
* Testen Sie die `get`-Methode mit gültigen Indizes und testen Sie die Ausnahme für ungültige Indizes.
* Testen Sie die `size`-Methode nach Hinzufügen und Entfernen von Elementen.

### Übung 5: Testen eines Passwort-Validierungs-Service

#### Klasse, die getestet werden soll: `PasswordValidator`

```java
public class PasswordValidator {
    public boolean validate(String password) {
        if (password == null) {
            throw new IllegalArgumentException("Passwort darf nicht null sein");
        }
        if (password.length() < 8) {
            return false;
        }
        if (!password.matches(".*\\d+.*")) {
            return false;
        }
        if (!password.matches(".*[A-Z].*")) {
            return false;
        }
        return true;
    }
}
```

#### Übung: Schreiben Sie JUnit-Tests für die `PasswordValidator`-Klasse.

* Testen Sie die `validate`-Methode mit null-Eingabe und überprüfen Sie die Ausnahme.
* Testen Sie die `validate`-Methode mit Passwörtern verschiedener Längen und Zusammensetzungen (z.B. fehlende Großbuchstaben,
  fehlende Zahlen).
* Testen Sie die `validate`-Methode mit gültigen Passwörtern.

[Junit 5 Gradle Starter](https://github.com/junit-team/junit5-samples/tree/main/junit5-jupiter-starter-gradle-groovy)