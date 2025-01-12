package org.example.university.repository;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import org.example.university.model.Course;
import org.example.university.model.Student;

public class StudentDBRepository extends DBRepository<Student> {
    public StudentDBRepository(String dbUrl, String dbUser, String dbPassword) {
        super(dbUrl, dbUser, dbPassword);
    }

    @Override
    public void create(Student obj) {
        String sql = "INSERT INTO Student (ID,name) VALUES (?,?)";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,obj.getID());
            statement.setString(2,obj.getName());

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Student read(Integer id) {
        String sql = "SELECT * FROM Student WHERE ID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,id);

            ResultSet resultSet = statement.executeQuery();

            if(resultSet.next()){
                return extractFromResultSetWithCourse(resultSet);
            } else {
                return null;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void update(Student obj) {
        String sql = "UPDATE Student SET name=? WHERE ID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setString(1,obj.getName());
            statement.setInt(2,obj.getID());

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        String sql2 = "DELETE FROM StudentCourse WHERE studentID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql2)){
            statement.setInt(1,obj.getID());

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        String sql3 = "INSERT INTO StudentCourse (studentID,courseID) VALUES (?, ?)";

        for(Course course : obj.getCourses()){
            try(PreparedStatement statement = connection.prepareStatement(sql3)){
                statement.setInt(1,obj.getID());
                statement.setInt(2,course.getID());

                statement.executeUpdate();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }

    @Override
    public void delete(Integer id) {
        String sql = "DELETE FROM Student WHERE ID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,id);
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        String sql2 = "DELETE FROM StudentCourse WHERE studentID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql2)){
            statement.setInt(1,id);
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<Student> getAll() {
        String sql = "SELECT * FROM Student";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            ResultSet resultSet = statement.executeQuery();

            List<Student> students = new ArrayList<>();

            while(resultSet.next()){
                students.add(extractFromResultSetWithCourse(resultSet));
            }

            return students;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public static Student extractFromResultSet(ResultSet resultSet) throws SQLException {
        return new Student(
                resultSet.getString("name"),
                resultSet.getInt("ID")
        );
    }

    public Student extractFromResultSetWithCourse(ResultSet resultSet) throws SQLException {
        Student student = new Student(
                resultSet.getString("name"),
                resultSet.getInt("ID")
        );

        try(PreparedStatement statement = connection
                .prepareStatement("SELECT * FROM Course where ID in (SELECT courseID FROM StudentCourse where studentID=?)")){
            statement.setInt(1,resultSet.getInt("ID"));
            ResultSet resultSet2 = statement.executeQuery();
            while(resultSet2.next()){
                student.getCourses().add(CourseDBRepository.extractFromResultSet(resultSet2,null,null));
            }

        }

        return student;
    }
}
