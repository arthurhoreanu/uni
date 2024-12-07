package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StringUtilsTest {

    @Test
    void testIsEmptyWithNull() {
        assertTrue(StringUtils.isEmpty(null));
    }

    @Test
    void testIsEmptyWithEmptyString() {
        assertTrue(StringUtils.isEmpty(""));
    }

    @Test
    void testIsEmptyWithWhitespace() {
        assertTrue(StringUtils.isEmpty("   "));
    }

    @Test
    void testIsEmptyWithNonEmptyString() {
        assertFalse(StringUtils.isEmpty("Hello"));
    }

    @Test
    void testTruncateWithShortString() {
        assertEquals("Hello", StringUtils.truncate("Hello", 10));
    }

    @Test
    void testTruncateWithLongString() {
        assertEquals("Hello", StringUtils.truncate("HelloWorld", 5));
    }

    @Test
    void testTruncateWithNullString() {
        assertThrows(IllegalArgumentException.class, () -> StringUtils.truncate(null, 5));
    }

    @Test
    void testTruncateWithNegativeLength() {
        assertThrows(IllegalArgumentException.class, () -> StringUtils.truncate("Hello", -1));
    }
}