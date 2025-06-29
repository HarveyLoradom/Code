package com.campus.course.mapper;

import com.campus.course.entity.Course;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface CourseMapper {
    Course selectById(@Param("id") Long id);
    List<Course> selectAll();
    int insertCourse(Course course);
    int updateCourse(Course course);
    int deleteCourse(@Param("id") Long id);
} 