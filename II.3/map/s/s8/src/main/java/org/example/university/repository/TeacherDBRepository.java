package org.example.university.repository;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import org.example.university.model.Teacher;

public class TeacherDBRepository extends DBRepository<Teacher> {

    public TeacherDBRepository(String dbUrl, String dbUser, String dbPassword) {
        super(dbUrl, dbUser, dbPassword);
    }

    @Override
    public void create(Teacher obj) {
        String sql = "INSERT INTO Teacher (ID, name) VALUES (?, ?)";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,obj.getID());
            statement.setString(2,obj.getName());

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Teacher read(Integer id) {
        String sql = "SELECT * FROM Teacher WHERE ID = ?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,id);

            ResultSet resultSet = statement.executeQuery();

            if(resultSet.next()){
                return extractFromResultSet(resultSet);
            } else {
                return null;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void update(Teacher obj) {
        String sql = "UPDATE Teacher SET name = ? WHERE ID = ?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setString(1,obj.getName());
            statement.setInt(2,obj.getID());

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public void delete(Integer id) {
        String sql = "DELETE FROM Teacher WHERE ID = ?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,id);

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<Teacher> getAll() {
        String sql = "SELECT * FROM Teacher";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            ResultSet resultSet = statement.executeQuery();

            List<Teacher> teachers = new ArrayList<>();

            while (resultSet.next()) {
                teachers.add(extractFromResultSet(resultSet));
            }

            return teachers;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static Teacher extractFromResultSet(ResultSet resultSet) throws SQLException {
        return new Teacher(
                resultSet.getString("name"),
                resultSet.getInt("ID")
        );
    }
}
