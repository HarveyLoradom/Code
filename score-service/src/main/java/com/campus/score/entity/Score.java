package com.campus.score.entity;

import lombok.Data;
import java.util.Date;

@Data
public class Score {
    private Long id;
    private Long studentId;
    private Long courseId;
    private Double score;
    private Date gradedAt;
} 