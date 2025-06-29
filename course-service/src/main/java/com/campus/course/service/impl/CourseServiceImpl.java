package com.campus.course.service.impl;

import com.campus.course.entity.Course;
import com.campus.course.mapper.CourseMapper;
import com.campus.course.service.CourseService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CourseServiceImpl implements CourseService {
    @Autowired
    private CourseMapper courseMapper;

    @Override
    public Course getCourseById(Long id) {
        return courseMapper.selectById(id);
    }

    @Override
    public List<Course> getAllCourses() {
        return courseMapper.selectAll();
    }

    @Override
    public Course addCourse(Course course) {
        courseMapper.insertCourse(course);
        return course;
    }

    @Override
    public Course updateCourse(Course course) {
        courseMapper.updateCourse(course);
        return course;
    }

    @Override
    public boolean deleteCourse(Long id) {
        return courseMapper.deleteCourse(id) > 0;
    }
} 