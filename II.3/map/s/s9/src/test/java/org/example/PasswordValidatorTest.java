package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PasswordValidatorTest {

    @Test
    void testValidateWithNull() {
        assertThrows(IllegalArgumentException.class, () -> new PasswordValidator().validate(null));
    }

    @Test
    void testValidateWithShortPassword() {
        assertFalse(new PasswordValidator().validate("Pass1"));
    }

    @Test
    void testValidateWithoutUppercase() {
        assertFalse(new PasswordValidator().validate("password1"));
    }

    @Test
    void testValidateWithoutNumber() {
        assertFalse(new PasswordValidator().validate("Password"));
    }

    @Test
    void testValidateWithValidPassword() {
        assertTrue(new PasswordValidator().validate("Password1"));
    }
}