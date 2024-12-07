package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class BankAccountTest {

    BankAccount account;

    @BeforeEach
    void setUp() {
        account = new BankAccount(100.0);
    }

    @Test
    void testConstructorWithPositiveBalance() {
        new BankAccount(100.0);
    }

    @Test
    void testConstructorWithZeroBalance() {
        new BankAccount(0.0);
    }

    @Test
    void testConstructorWithNegativeBalance() {
        assertThrows(IllegalArgumentException.class, () -> new BankAccount(-100.0));
    }

    @Test
    void testDepositPositiveAmount() {
        account.deposit(50.0);
        assertEquals(150.0, account.getBalance());
    }

    @Test
    void testDepositNonPositiveAmount() {
        assertThrows(IllegalArgumentException.class, () -> account.deposit(-50.0));
    }

    @Test
    void testWithdrawPositiveAmount() {
        account.withdraw(50.0);
        assertEquals(50.0, account.getBalance());
    }

    @Test
    void testWithdrawNonPositiveAmount() {
        assertThrows(IllegalArgumentException.class, () -> account.withdraw(-50.0));
    }

    @Test
    void testWithdrawInsufficientFunds() {
        assertThrows(IllegalArgumentException.class, () -> account.withdraw(200.0));
    }
}