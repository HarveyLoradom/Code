package com.campus.course.service;

import com.campus.course.entity.Course;
import java.util.List;

public interface CourseService {
    Course getCourseById(Long id);
    List<Course> getAllCourses();
    Course addCourse(Course course);
    Course updateCourse(Course course);
    boolean deleteCourse(Long id);
} 