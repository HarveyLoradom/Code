package com.campus.course.service;

import com.campus.course.entity.CourseSelection;
import java.util.List;

public interface CourseSelectionService {
    List<CourseSelection> getSelectionsByStudentId(Long studentId);
    List<CourseSelection> getSelectionsByCourseId(Long courseId);
    boolean selectCourse(Long studentId, Long courseId);
    boolean dropCourse(Long studentId, Long courseId);
    void deleteSelection(Long id);
    int getSelectionCount();
} 