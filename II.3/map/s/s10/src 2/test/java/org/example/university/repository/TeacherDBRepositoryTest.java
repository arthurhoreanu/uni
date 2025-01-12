package org.example.university.repository;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import org.example.university.model.Teacher;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

@ExtendWith(MockitoExtension.class)
class TeacherDBRepositoryTest {
    private static final String URL = "jdbc:h2:mem:testdb;DB_CLOSE_DELAY=-1";

    private static final String USER = "sa";

    private static final String PASSWORD = "";

    private TeacherDBRepository teacherDBRepository;

    private static Connection testConnection;

    @Mock
    private Connection connection;

    private TeacherDBRepository repository;

    @BeforeAll
    public static void init() throws SQLException {
        testConnection = DriverManager.getConnection(URL, USER, PASSWORD);
        PreparedStatement preparedStatement = testConnection.prepareStatement("create table IF NOT EXISTS Teacher ("
                + "ID int null,"
                + "name varchar(50) null"
                + ");");
        preparedStatement.executeUpdate();
    }

    @AfterAll
    public static void tearDown() throws SQLException {
        testConnection.close();
    }

    @BeforeEach
    public void setUp() {
        teacherDBRepository = new TeacherDBRepository(URL, USER, PASSWORD);
        repository = new TeacherDBRepository(connection);
    }

    @AfterEach
    public void destroy() throws SQLException {
        testConnection.prepareStatement("DELETE FROM Teacher").execute();
        teacherDBRepository = null;
    }

    @Test
    void testCreate() throws SQLException {
        Teacher teacher = new Teacher("John Doe", 1);
        teacherDBRepository.create(teacher);

        PreparedStatement preparedStatement = testConnection.prepareStatement("SELECT * FROM Teacher");
        ResultSet resultSet = preparedStatement.executeQuery();
        assertTrue(resultSet.next());
        assertEquals(teacher.getName(), resultSet.getString("name"));
        assertEquals(teacher.getID(), resultSet.getInt("ID"));
        assertFalse(resultSet.next());
    }

    @Test
    void testCreateException() throws SQLException {
        Teacher teacher = new Teacher("John Doe", 1);

        PreparedStatement preparedStatement = mock(PreparedStatement.class);
        when(connection.prepareStatement(anyString())).thenReturn(preparedStatement);
        when(preparedStatement.execute()).thenThrow(new SQLException());

        assertThrows(RuntimeException.class, () -> repository.create(teacher));
    }

    @Test
    void testDelete() throws SQLException {
        testConnection.prepareStatement("Insert INTO Teacher(ID,name) VALUES(1,'Jon Doe')").executeUpdate();
        teacherDBRepository.delete(1);
        ResultSet resultSet = testConnection.prepareStatement("SELECT count(*) FROM Teacher").executeQuery();
        assertTrue(resultSet.next());
        assertEquals(0, resultSet.getInt(1));
    }

    @Test
    void testDeleteException() throws SQLException {
        PreparedStatement preparedStatement = mock(PreparedStatement.class);
        when(connection.prepareStatement(anyString())).thenReturn(preparedStatement);
        when(preparedStatement.execute()).thenThrow(new SQLException());

        assertThrows(RuntimeException.class, () -> repository.delete(1));
    }

    @Test
    void testRead() throws SQLException {
        testConnection.prepareStatement("Insert INTO Teacher(ID,name) VALUES(1,'Jon Doe')").executeUpdate();

        Teacher teacher = teacherDBRepository.read(1);

        assertNotNull(teacher);
        assertEquals("Jon Doe", teacher.getName());
    }

    @Test
    void testReadException() throws SQLException {
        PreparedStatement value = mock(PreparedStatement.class);
        when(connection.prepareStatement(anyString())).thenReturn(value);
        when(value.executeQuery()).thenThrow(new SQLException());

        assertThrows(RuntimeException.class, () -> repository.read(1));
    }

    @Test
    void testUpdate() throws SQLException {
        testConnection.prepareStatement("INSERT INTO Teacher(ID,name) VALUES(1,'Jon Doe')").executeUpdate();
        Teacher teacher = new Teacher("Ion doe", 1);
        teacherDBRepository.update(teacher);
        ResultSet resultSet = testConnection.prepareStatement("SELECT * FROM Teacher WHERE ID = 1").executeQuery();
        assertTrue(resultSet.next());
        assertEquals("Ion doe", resultSet.getString("Name"));
    }

    @Test
    void testUpdateException() throws SQLException {
        PreparedStatement value = mock(PreparedStatement.class);
        when(connection.prepareStatement(anyString())).thenReturn(value);
        when(value.execute()).thenThrow(new SQLException());
        assertThrows(RuntimeException.class, () -> repository.update(new Teacher("Ion doe", 1)));
    }

    @Test
    void getAllTest() throws SQLException {
        testConnection.prepareStatement("INSERT INTO Teacher(ID,name) VALUES(1,'Jon Doe')").executeUpdate();
        testConnection.prepareStatement("INSERT INTO Teacher(ID,name) VALUES(2,'Jon One')").executeUpdate();
        testConnection.prepareStatement("INSERT INTO Teacher(ID,name) VALUES(3,'Jon Two')").executeUpdate();

        List<Teacher> list = teacherDBRepository.getAll();
        assertThat(list)
                .hasSize(3)
                .anyMatch(teacher -> teacher.getName().equals("Jon Doe"))
                .anyMatch(teacher -> teacher.getName().equals("Jon One"))
                .anyMatch(teacher -> teacher.getName().equals("Jon Two"));
    }

    @Test
    void getAllException() throws SQLException {
        PreparedStatement value = mock(PreparedStatement.class);
        when(connection.prepareStatement(anyString())).thenReturn(value);
        when(value.executeQuery()).thenThrow(new SQLException());
        assertThrows(RuntimeException.class, () -> repository.getAll());
    }
}