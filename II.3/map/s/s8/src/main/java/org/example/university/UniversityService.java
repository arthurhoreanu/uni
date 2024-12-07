package org.example.university;

import java.util.List;

import org.example.university.model.Course;
import org.example.university.model.Student;
import org.example.university.repository.Repository;


public class UniversityService {

    private Repository<Student> students;
    private Repository<Course> courses;

    UniversityService(Repository<Student> stud, Repository<Course> cors){
        courses = cors;
        students = stud;
    }

    public List<Student> getStudents(){

        return students.getAll();
    }

    public List<Course> getCourses(){
        return courses.getAll();
    }

    public void enrolledStudent(Integer studentId,Integer courseId ){
        Student stud = students.read(studentId);
        Course course = courses.read(courseId);
        //Verify if the Course has places
        if(course.getAvailableSlots() > course.getEnrolledStudents().size() &&
                stud.getCourses().stream().mapToInt(Course::getCredits).sum() < 10){

                course.getEnrolledStudents().add(stud);
                stud.getCourses().add(course);
                //Update repos
                students.update(stud);
                courses.update(course);

        }

    }

    public List<Student> getEnrolledStudents(Integer courseId){
        Course course = courses.read(courseId);
        return course.getEnrolledStudents();
    }

    public void removeCourse(Integer courseId){
        Course course = courses.read(courseId);
        for(Student stud: course.getEnrolledStudents()){
            stud.getCourses().removeIf(cor -> cor.getID().equals(courseId));
            students.update(stud);
        }
    }

}
