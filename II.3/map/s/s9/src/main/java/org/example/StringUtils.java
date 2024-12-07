package org.example;

public class StringUtils {

    private StringUtils(){}

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
