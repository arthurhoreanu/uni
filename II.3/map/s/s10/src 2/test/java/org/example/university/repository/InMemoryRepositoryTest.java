package org.example.university.repository;

import java.util.HashMap;
import java.util.Map;

import org.example.university.HasIdImpl;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Spy;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.mockito.Mockito.verify;

@ExtendWith(MockitoExtension.class)
class InMemoryRepositoryTest {

    @Spy
    private Map<Integer, HasIdImpl> map = new HashMap<>();

    private InMemoryRepository<HasIdImpl> repo;

    @BeforeEach
    public void setUp() {
        repo = new InMemoryRepository<>();
        repo.map = map;
    }

    @Test
    void create() {
        HasIdImpl hasId = new HasIdImpl(1);

        repo.create(hasId);

        verify(map).putIfAbsent(1, hasId);
    }

    @Test
    void update() {
        HasIdImpl hasId = new HasIdImpl(1);

        repo.update(hasId);

        verify(map).replace(1, hasId);
    }

    @Test
    void delete() {
        repo.delete(1);

        verify(map).remove(1);
    }

    @Test
    void read() {
        repo.read(1);
        verify(map).get(1);
    }

    @Test
    void getAll() {
        repo.getAll();
        verify(map).values();
    }
}