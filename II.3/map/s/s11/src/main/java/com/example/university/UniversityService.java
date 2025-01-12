package com.example.university;

import java.util.ArrayList;
import java.util.List;

import com.example.university.model.Course;
import com.example.university.model.Student;
import com.example.university.repository.CourseRepository;
import com.example.university.repository.StudentRepository;
import com.example.university.repository.TeacherRepository;
import lombok.AllArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional
@AllArgsConstructor(onConstructor = @__(@Autowired))
public class UniversityService {

    private StudentRepository studentRepository;

    private CourseRepository courseRepository;

    private TeacherRepository teacherRepository;

    public List<Student> getAllStudents() {
        return studentRepository.findAll();
    }

    public List<Course> getAllCourses() {
        return courseRepository.findAll();
    }

    public List<Student> getEnrolledStudents(Integer courseId) {
        return courseRepository
                .findById(courseId)
                .map(Course::getStudents)
                .orElse(new ArrayList<>());
    }

    public void removeCourse(Integer courseId) {
        courseRepository.deleteById(courseId);
    }

    public void enrollStudent(Integer studentId, Integer courseId) {
        Student stud = studentRepository.findById(studentId).orElseThrow();
        Course course = courseRepository.findById(courseId).orElseThrow();

        if (course.getAvailableSlots() > course.getStudents().size() &&
                stud.getCourses().stream().mapToInt(Course::getCredits).sum() < 10) {
            course.getStudents().add(stud);
            stud.getCourses().add(course);

            studentRepository.save(stud);
            courseRepository.save(course);
        }
    }
}
