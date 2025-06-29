package com.campus.course.mapper;

import com.campus.course.entity.CourseSelection;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import java.util.List;

@Mapper
public interface CourseSelectionMapper {
    List<CourseSelection> selectByStudentId(@Param("studentId") Long studentId);
    List<CourseSelection> selectByCourseId(@Param("courseId") Long courseId);
    CourseSelection selectById(@Param("id") Long id);
    int insertSelection(CourseSelection selection);
    int deleteSelection(@Param("studentId") Long studentId, @Param("courseId") Long courseId);
    int countAll();
} 