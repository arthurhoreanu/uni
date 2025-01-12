package org.example.university.repository;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import org.example.university.model.Course;
import org.example.university.model.Student;
import org.example.university.model.Teacher;

public class CourseDBRepository extends DBRepository<Course> {

    TeacherDBRepository teacherRepository;

    public CourseDBRepository(String dbUrl, String dbUser, String dbPassword) {
        super(dbUrl, dbUser, dbPassword);
        this.teacherRepository = new TeacherDBRepository(dbUrl, dbUser, dbPassword);
    }

    @Override
    public void create(Course obj) {
        String sql = "INSERT INTO Course (ID,availableSlots,credits,courseName,teacherID) VALUES(?, ?, ?, ?, ?)";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,obj.getID());
            statement.setInt(2,obj.getAvailableSlots());
            statement.setDouble(3,obj.getCredits());
            statement.setString(4,obj.getCourseName());
            statement.setInt(5,obj.getTeacher().getID());

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Course read(Integer id) {
        String sql = "SELECT * FROM Course WHERE ID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,id);

            ResultSet resultSet = statement.executeQuery();
            if(resultSet.next()){
                Teacher teacher = teacherRepository.read(resultSet.getInt("teacherID"));
                ArrayList<Student> students = getCourseStudents(id);

                return extractFromResultSet(resultSet, teacher, students);

            } else {
                return null;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void update(Course obj) {
        String sql = "UPDATE Course SET availableSlots=?,credits=?,courseName=?,teacherID=? WHERE ID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,obj.getAvailableSlots());
            statement.setDouble(2,obj.getCredits());
            statement.setString(3,obj.getCourseName());
            statement.setInt(4,obj.getTeacher().getID());
            statement.setInt(5,obj.getID());

            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void delete(Integer id) {
        String sql = "DELETE FROM Course WHERE ID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,id);
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        String sql2 = "DELETE FROM StudentCourse WHERE courseID=?";

        try(PreparedStatement statement = connection.prepareStatement(sql2)){
            statement.setInt(1,id);
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<Course> getAll() {
        String sql = "SELECT * FROM Course";

        try(PreparedStatement statement = connection.prepareStatement(sql)){
            ResultSet resultSet = statement.executeQuery();

            List<Course> courses = new ArrayList<>();

            while(resultSet.next()){
                Teacher teacher = teacherRepository.read(resultSet.getInt("teacherID"));
                ArrayList<Student> students = getCourseStudents(resultSet.getInt("ID"));

                courses.add(extractFromResultSet(resultSet, teacher, students));
            }

            return courses;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public static Course extractFromResultSet(ResultSet resultSet, Teacher teacher, List<Student> students) throws SQLException {
        Course course = new Course(
                resultSet.getInt("ID"),
                resultSet.getString("courseName"),
                teacher,
                resultSet.getInt("availableSlots"),
                resultSet.getInt("credits")
        );
        course.setEnrolledStudents(students);
        return course;
    }

    private ArrayList<Student> getCourseStudents(Integer id) {
        ArrayList<Student> students = new ArrayList<>();
        String sqlEnrolledStudents =
                "SELECT st.ID, st.name FROM Student as st "
                        + "where ID in (SELECT StudentCourse.studentID FROM StudentCourse WHERE courseID = ?)";

        try(PreparedStatement statementEnrolledStudents = connection.prepareStatement(sqlEnrolledStudents)){
            statementEnrolledStudents.setInt(1, id);

            ResultSet resultSetEnrolledStudents = statementEnrolledStudents.executeQuery();


            while(resultSetEnrolledStudents.next()){
                students.add(StudentDBRepository.extractFromResultSet(resultSetEnrolledStudents));
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return students;
    }
}
