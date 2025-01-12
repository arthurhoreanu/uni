package org.example.user;

public interface UserRepository {
    void save(User user);
    void save(String user);
}
