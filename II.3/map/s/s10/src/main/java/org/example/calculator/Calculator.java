package org.example.calculator;

public class Calculator {
    private final Operation operation;

    public Calculator(Operation operation) {
        this.operation = operation;
    }

    public int compute(int a, int b) {
        return operation.execute(a, b);
    }
}
