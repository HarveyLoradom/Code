package com.campus.score.service;

import com.campus.score.entity.Score;
import java.util.List;

public interface ScoreService {
    List<Score> getAllScores();
    Score getScoreById(Long id);
    List<Score> getScoresByStudentId(Long studentId);
    List<Score> getScoresByCourseId(Long courseId);
    Score addScore(Score score);
    Score updateScore(Score score);
    boolean deleteScore(Long id);
    int getScoreCount();
} 