package com.campus.course.entity;

import lombok.Data;
import java.util.Date;

@Data
public class Course {
    private Long id;
    private String courseCode;
    private String courseName;
    private Long teacherId;
    private String teacherName;
    private Double credit;
    private Integer capacity;
    private Integer selectedCount;
    private String schedule;
    private Date createdAt;
} 