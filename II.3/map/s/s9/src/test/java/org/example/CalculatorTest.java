package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class CalculatorTest {

    Calculator calculator;

    @Test
    void testAddPositiveNumbers() {
        assertEquals(5, calculator.add(2, 3));
    }

    @Test
    void testAddNegativeNumbers() {
        assertEquals(-5, calculator.add(-2, -3));
    }

    @Test
    void testAddZero() {
        assertEquals(0, calculator.add(0, 0));
    }

    @Test
    void testSubtractPositiveNumbers() {
        assertEquals(5, calculator.subtract(10, 5));
    }

    @Test
    void testSubtractNegativeNumbers() {
        assertEquals(1, calculator.subtract(-2, -3));
    }

    @Test
    void testSubtractZero() {
        assertEquals(0, calculator.subtract(0, 0));
    }

    @Test
    void testMultiplyPositiveNumbers() {
        assertEquals(6, calculator.multiply(2, 3));
    }

    @Test
    void testMultiplyNegativeNumbers() {
        assertEquals(6, calculator.multiply(-2, -3));
    }

    @Test
    void testMultiplyZero() {
        assertEquals(0, calculator.multiply(0, 0));
    }

    @Test
    void testDividePositiveNumbers() {
        assertEquals(2, calculator.divide(6, 3));
    }

    @Test
    void testDivideNegativeNumbers() {
        assertEquals(2, calculator.divide(-6, -3));
    }

    @Test
    void testDivideByZero() {
        assertThrows(ArithmeticException.class, () -> calculator.divide(6, 0));
    }
}