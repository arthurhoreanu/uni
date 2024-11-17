package university.model;

/**
 * An abstract class that represents a person in the university system.
 */
public abstract class Person implements HasId {
    protected String name;
    protected Integer id;

    /**
     * Constructs a new Person with the specified ID and name.
     *
     * @param id   The unique identifier for the person.
     * @param name The name of the person.
     */
    protected Person(Integer id, String name) {
        this.name = name;
        this.id = id;
    }

    /**
     * Gets the name of the person.
     *
     * @return The name of the person.
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the name of the person.
     *
     * @param name The name to set.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Gets the unique identifier for the person.
     *
     * @return The unique identifier.
     */
    public Integer getId() {
        return id;
    }

    /**
     * Sets the unique identifier for the person.
     *
     * @param id The unique identifier to set.
     */
    public void setId(Integer id) {
        this.id = id;
    }
}