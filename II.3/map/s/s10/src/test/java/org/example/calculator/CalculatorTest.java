package org.example.calculator;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

@ExtendWith(MockitoExtension.class)
class CalculatorTest {

    @Mock
    private Operation operation;

    @Test
    void testAdd() {
        Calculator calculator = new Calculator(new Addition());
        assertEquals(3, calculator.compute(1, 2));
    }

    @Test
    void testSubtract() {
        Calculator calculator = new Calculator(new Subtraction());
        assertEquals(3, calculator.compute(5, 2));
    }

    @Test
    void testCompute() {
        Calculator calculator = new Calculator(operation);
        when(operation.execute(anyInt(), anyInt())).thenReturn(1);

        assertEquals(1, calculator.compute(1, 1));
    }

    @Test
    void testComputeAnswer() {
        Calculator calculator = new Calculator(operation);
        when(operation.execute(anyInt(), anyInt())).thenAnswer(invocation ->
                (Integer) invocation.getArgument(0) * (Integer) invocation.getArgument(1));

        assertEquals(4, calculator.compute(2, 2));
    }

    @Test
    void testInteaction() {
        Calculator calculator = new Calculator(operation);
        when(operation.execute(anyInt(), anyInt())).thenReturn(2);

        calculator.compute(1,1);

        verify(operation).execute(anyInt(), anyInt());
    }

}