package org.example.university.repository;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import org.example.university.model.HasID;

public abstract class DBRepository<T extends HasID> implements Repository<T>, AutoCloseable {

    protected final Connection connection;

    public DBRepository(final Connection connection) {
        this.connection = connection;
    }

    public DBRepository(String dbUrl, String dbUser, String dbPassword) {
        try {
            connection = DriverManager.getConnection(dbUrl, dbUser, dbPassword);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void close() throws Exception {
        connection.close();
    }
}
