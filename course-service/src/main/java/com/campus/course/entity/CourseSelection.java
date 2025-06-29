package com.campus.course.entity;

import lombok.Data;
import java.util.Date;

@Data
public class CourseSelection {
    private Long id;
    private Long studentId;
    private Long courseId;
    private Date selectedAt;
    
    // 关联查询的课程信息
    private String courseCode;
    private String courseName;
    private Integer credit;
    private String schedule;
} 