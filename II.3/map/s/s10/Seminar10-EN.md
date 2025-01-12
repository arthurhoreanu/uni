# Integration Testing in Java

Integration testing is a level of software testing where individual components or modules of a software system are combined and tested as a group. The purpose of integration testing is to ensure that the integrated components work together correctly and that the system as a whole functions as expected. In Java, integration testing is often performed using testing frameworks like JUnit, along with mocking libraries such as Mockito to isolate dependencies.

## Exercises

### Exercise 1: Testing a Simple Calculator
Consider the following classes:

```java
public class Calculator {
    private final Operation operation;

    public Calculator(Operation operation) {
        this.operation = operation;
    }

    public int compute(int a, int b) {
        return operation.execute(a, b);
    }
}

public interface Operation {
    int execute(int a, int b);
}

public class Addition implements Operation {
    @Override
    public int execute(int a, int b) {
        return a + b;
    }
}

public class Subtraction implements Operation {
    @Override
    public int execute(int a, int b) {
        return a - b;
    }
}
```

Write an integration test to verify that the `Calculator` class correctly delegates the computation to the `Addition` and `Subtraction` operations.

### Exercise 2: Testing a Service Layer
Consider the following classes:

```java
public class UserService {
    private final UserRepository userRepository;

    public UserService(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    public User createUser(String name, int age) {
        User user = new User(name, age);
        userRepository.save(user);
        return user;
    }
}

public interface UserRepository {
    void save(User user);
}

public class User {
    private String name;
    private int age;

    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // getters and setters
}
```

Write an integration test to verify that the `UserService` correctly creates and saves a `User` object using the `UserRepository`.

### Exercise 3: Testing a Web Service Client
Consider the following classes:

```java
public class WebClient {
    private final HttpService httpService;

    private final Map<String,String> headers;

    @Builder
    private WebClient(HttpService httpService, Map<String,String> headers) {
        this.httpService = httpService;
        this.headers = headers;
    }

    public String getData(String url) {
        return httpService.get(url, headers);
    }
}

public interface HttpService {
    String get(String url);
}
```
Write an integration test to verify that the `WebClient` correctly interacts with the `HttpService` to retrieve data from a given URL.

### Exercise 4: Integration Testing with H2 in Java using JDBC
Create an integration test for a UserRepository that uses an in-memory H2 database to verify the CRUD operations using only JDBC.

```java
@Data
@AllArgsConstructor
public class User {
    private Long id;
    private String name;
    private String email;
}
```

```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class UserRepository {

    private final String url;
    private final String user;
    private final String password;

    public UserRepository(String url, String user, String password) {
        this.url = url;
        this.user = user;
        this.password = password;

        try (Connection conn = DriverManager.getConnection(url, user, password);) {
            createTable(conn);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void createTable(Connection conn) throws SQLException {
        String sql = "CREATE TABLE IF NOT EXISTS users (" +
                "id IDENTITY PRIMARY KEY, " +
                "name VARCHAR(255) NOT NULL, " +
                "email VARCHAR(255) NOT NULL)";
        try (PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.execute();
        }
    }

    public User save(User user) throws SQLException {
        String sql = "INSERT INTO users (name, email) VALUES (?, ?)";
        try (Connection conn = DriverManager.getConnection(this.url, this.user, this.password);
                PreparedStatement stmt = conn.prepareStatement(sql, PreparedStatement.RETURN_GENERATED_KEYS)) {
            stmt.setString(1, user.getName());
            stmt.setString(2, user.getEmail());
            stmt.executeUpdate();
            try (ResultSet generatedKeys = stmt.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    user.setId(generatedKeys.getLong(1));
                }
            }
        }
        return user;
    }

    public User findById(Long id) throws SQLException {
        String sql = "SELECT * FROM users WHERE id = ?";
        try (Connection conn = DriverManager.getConnection(this.url, this.user, this.password);
                PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setLong(1, id);
            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) {
                    return new User(rs.getLong("id"), rs.getString("name"), rs.getString("email"));
                }
            }
        }
        return null;
    }

    public void delete(User user) throws SQLException {
        String sql = "DELETE FROM users WHERE id = ?";
        try (Connection conn = DriverManager.getConnection(this.url, this.user, this.password);
                PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setLong(1, user.getId());
            stmt.executeUpdate();
        }
    }

    public List<User> findAll() throws SQLException {
        String sql = "SELECT * FROM users";
        List<User> users = new ArrayList<>();
        try (Connection conn = DriverManager.getConnection(this.url, this.user, this.password);
                PreparedStatement stmt = conn.prepareStatement(sql);
                ResultSet rs = stmt.executeQuery()) {
            while (rs.next()) {
                users.add(new User(rs.getLong("id"), rs.getString("name"), rs.getString("email")));
            }
        }
        return users;
    }
}
```

# Extras
### Example dependencies
```groovy
dependencies {
    implementation 'com.mysql:mysql-connector-j:9.1.0'

    implementation(localGroovy())
    testImplementation(platform('org.junit:junit-bom:5.11.3'))
    testImplementation('org.junit.jupiter:junit-jupiter')
    testRuntimeOnly('org.junit.platform:junit-platform-launcher')
    testImplementation 'org.mockito:mockito-junit-jupiter:5.14.2'
    testImplementation 'org.assertj:assertj-core:3.26.3'

    testImplementation 'com.h2database:h2:2.3.232'
}
```