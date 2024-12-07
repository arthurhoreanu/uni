# Unit Testing in Java

Unit testing is a fundamental practice in software development that involves testing individual units or components of
a software application to ensure they work as expected. In Java,
unit testing is typically performed using testing frameworks like JUnit.
The goal of unit testing is to verify that each part of the code behaves correctly in isolation,
which helps in identifying and fixing bugs early in the development process.

## Key Concepts in Unit Testing

**Test Cases**: A test case is a set of conditions or variables under which a tester will determine if an application is
working correctly.

**Test Methods**: These are individual methods within a test class that contain assertions to verify the behavior of the code
being tested.

**Assertions**: Assertions are checks that verify if the output of a method matches the expected result. Common assertions in
JUnit include `assertEquals()`, `assertTrue()` und `assertNull()`.

**Test Suites**: A test suite is a collection of test cases that can be run together.

**Setup and Teardown**: These are methods that are run before and after each test method to set up the necessary conditions
or clean up resources.

## Best Practices in Unit Testing

**Keep Tests Independent**: Each test should be independent of others, meaning the outcome of one test should not affect
another.

**Test One Thing at a Time:** Each test method should focus on verifying one specific aspect of the code.

**Use Meaningful Test Names**: Test names should clearly describe what is being tested.

**Cover Edge Cases**: Ensure that your tests cover edge cases and boundary conditions.

## Exercises

### Exercise 1: Testing a Simple Calculator

#### Class to be Tested: `Calculator`

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
            throw new ArithmeticException("Division by zero");
        }
        return a / b;
    }
}
```

#### Exercise: Write JUnit tests for the `Calculator` class.

* Test the `add` method with positive numbers, negative numbers, and zero.
* Test the `subtract` method with positive numbers, negative numbers, and zero.
* Test the `multiply` method with positive numbers, negative numbers, and zero.
* Test the `divide` method with positive numbers, negative numbers, and test the exception when dividing by zero.

### Exercise 2: Testing a String Utility Class

### Class to be Tested: `StringUtils`

```java
public class StringUtils {
    public static boolean isEmpty(String str) {
        return str == null || str.trim().isEmpty();
    }

    public static String truncate(String str, int length) {
        if (str == null) {
            throw new IllegalArgumentException("String cannot be null");
        }
        if (length < 0) {
            throw new IllegalArgumentException("Length cannot be negative");
        }
        if (str.length() <= length) {
            return str;
        }
        return str.substring(0, length);
    }
}
```

#### Exercise: Write JUnit tests for the `StringUtils` class.

* Test the `isEmpty` method with null, empty string, whitespace, and non-empty strings.
* Test the `truncate` method with strings of various lengths, including cases where the string is shorter than the specified
  length, and test the exceptions for invalid inputs.

### Exercise 3: Testing a Bank Account Class

#### Class to be Tested: `BankAccount`

```java
public class BankAccount {
    private double balance;

    public BankAccount(double initialBalance) {
        if (initialBalance < 0) {
            throw new IllegalArgumentException("Initial balance cannot be negative");
        }
        this.balance = initialBalance;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Deposit amount must be positive");
        }
        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Withdrawal amount must be positive");
        }
        if (balance < amount) {
            throw new IllegalArgumentException("Insufficient funds");
        }
        balance -= amount;
    }
}
```

#### Exercise: Write JUnit tests for the `BankAccount` class.

* Test the constructor with positive, zero, and negative initial balances.
* Test the `deposit` method with positive amounts and test the exception for non-positive amounts.
* Test the `withdraw` method with positive amounts, insufficient funds, and test the exception for non-positive amounts.

### Exercise 4: Testing a Custom List Class

#### Class to be Tested: `CustomList`

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
            throw new IndexOutOfBoundsException("Index out of range");
        }
        return list.get(index);
    }

    public int size() {
        return list.size();
    }
}
```

#### Exercise: Write JUnit tests for the `CustomList` class.

* Test the `add` method by adding elements and checking the size.
* Test the `get` method with valid indices and test the exception for invalid indices.
* Test the `size` method after adding and removing elements.

### Exercise 5: Testing a Password Validator

#### Class to be Tested: `PasswordValidator`

```java
public class PasswordValidator {
    public boolean validate(String password) {
        if (password == null) {
            throw new IllegalArgumentException("Password cannot be null");
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

#### Exercise: Write JUnit tests for the `PasswordValidator` class.

* Test the `validate` method with null input and check the exception.
* Test the `validate` method with passwords of various lengths and compositions (e.g., missing uppercase letters, missing
  numbers).
* Test the `validate` method with valid passwords.

[Junit 5 Gradle Starter](https://github.com/junit-team/junit5-samples/tree/main/junit5-jupiter-starter-gradle-groovy)