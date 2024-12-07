package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class CustomListTest {

    @Test
    void testAddAndSize() {
        CustomList<String> list = new CustomList<>();
        list.add("Apple");
        list.add("Banana");
        assertEquals(2, list.size());
    }

    @Test
    void testGetValidIndex() {
        CustomList<String> list = new CustomList<>();
        list.add("Apple");
        list.add("Banana");
        assertEquals("Banana", list.get(1));
    }

    @Test
    void testGetInvalidIndex() {
        CustomList<String> list = new CustomList<>();
        list.add("Apple");
        assertThrows(IndexOutOfBoundsException.class, () -> list.get(1));
    }
}