package org.example.dbuser;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class UserRepositoryTest {
    private static final String URL = "jdbc:h2:mem:testdb;DB_CLOSE_DELAY=-1";
    private static final String USER = "sa";
    private static final String PASSWORD = "";

    private UserRepository repo;
    private static Connection testConnection;

    @BeforeAll
    static void setUpBeforeClass() throws Exception {
        testConnection = DriverManager.getConnection(URL, USER, PASSWORD);
        UserRepository.createTable(testConnection);
    }

    @AfterAll
    static void tearDownAfterClass() throws Exception {
        testConnection.close();
    }

    @BeforeEach
    public void setUp() {
        repo = new UserRepository(URL, USER, PASSWORD);
    }

    @AfterEach
    public void tearDown() throws SQLException {
        repo = null;
        testConnection.prepareStatement("DELETE FROM users").execute();
    }

    @Test
    void createUser() throws SQLException {
        User user = new User(1L, "Name1", "a@b.c");

        repo.save(user);

        ResultSet resultSet = testConnection.prepareStatement("SELECT * FROM users").executeQuery();
        assertTrue(resultSet.next());
        assertEquals("Name1", resultSet.getString("name"));
        assertEquals("a@b.c", resultSet.getString("email"));
        assertFalse(resultSet.next());
    }

    @Test
    void deleteUser() throws SQLException {
        testConnection.prepareStatement("INSERT INTO users(id,name,email) VALUES (1,'Name1','a@b.c')").execute();


        User user = new User(1L, "Name1", "a@b.c");
        repo.delete(user);

        ResultSet resultSet = testConnection.prepareStatement("SELECT count(*) FROM users").executeQuery();
        assertTrue(resultSet.next());
        assertEquals(0, resultSet.getInt(1));
    }

    @Test
    void findById() throws SQLException {
        testConnection.prepareStatement("INSERT INTO users(id,name,email) VALUES (1,'Name1','a@b.c')").execute();

        User user = repo.findById(1L);

        assertEquals(1L, user.getId());
        assertEquals("Name1", user.getName());
        assertEquals("a@b.c", user.getEmail());
    }

    @Test
    void findAll() throws SQLException {
        testConnection.prepareStatement("INSERT INTO users(id,name,email) VALUES (1,'Name1','a1@b.c')").execute();
        testConnection.prepareStatement("INSERT INTO users(id,name,email) VALUES (2,'Name2','a2@b.c')").execute();
        testConnection.prepareStatement("INSERT INTO users(id,name,email) VALUES (3,'Name3','a3@b.c')").execute();

        List<User> users = repo.findAll();

        assertThat(users)
                .hasSize(3)
                .allSatisfy(user -> {
                    Long id = user.getId();
                    assertThat(id).isNotNull();
                    assertThat(user.getName()).startsWith("Name").endsWith(id.toString());
                    assertThat(user.getEmail()).startsWith("a")
                            .contains(id.toString())
                            .endsWith("@b.c");
                });

    }

    @Test
    void testSaveAndFindUser() throws SQLException {
        User user = new User(null, "John Doe", "john.doe@example.com");
        User savedUser = repo.save(user);
        assertNotNull(savedUser);
        assertNotNull(savedUser.getId());

        User foundUser = repo.findById(savedUser.getId());
        assertNotNull(foundUser);
        assertEquals("John Doe", foundUser.getName());
        assertEquals("john.doe@example.com", foundUser.getEmail());
    }

    @Test
    void testDeleteUser() throws SQLException {
        User user = new User(null, "Jane Doe", "jane.doe@example.com");
        User savedUser = repo.save(user);
        assertNotNull(savedUser);
        assertNotNull(savedUser.getId());

        repo.delete(savedUser);
        User foundUser = repo.findById(savedUser.getId());
        assertNull(foundUser);
    }
  
}