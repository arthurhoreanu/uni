package org.example.calculator;

public class Subtraction implements Operation {
    @Override
    public int execute(int a, int b) {
        return a - b;
    }
}
