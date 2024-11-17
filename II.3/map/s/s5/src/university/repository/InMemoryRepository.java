package university.repository;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import university.model.HasId;

/**
 * A repository implementation that stores data in memory.
 *
 * @param <T> The type of objects stored in the repository, which must implement HasId.
 */
public class InMemoryRepository<T extends HasId> implements Repository<T> {
    private final Map<Integer, T> data = new HashMap<>();

    /**
     * {@inheritDoc}
     */
    @Override
    public void create(T obj) {
        data.putIfAbsent(obj.getId(), obj);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public T get(Integer id) {
        return data.get(id);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void update(T obj) {
        data.replace(obj.getId(), obj);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void delete(Integer id) {
        data.remove(id);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<T> getAll() {
        return data.values().stream().toList();
    }
}