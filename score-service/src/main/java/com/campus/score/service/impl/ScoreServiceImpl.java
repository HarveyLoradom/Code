package com.campus.score.service.impl;

import com.campus.score.entity.Score;
import com.campus.score.mapper.ScoreMapper;
import com.campus.score.service.ScoreService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ScoreServiceImpl implements ScoreService {
    @Autowired
    private ScoreMapper scoreMapper;

    @Override
    public List<Score> getAllScores() {
        return scoreMapper.selectAll();
    }

    @Override
    public Score getScoreById(Long id) {
        return scoreMapper.selectById(id);
    }

    @Override
    public List<Score> getScoresByStudentId(Long studentId) {
        return scoreMapper.selectByStudentId(studentId);
    }

    @Override
    public List<Score> getScoresByCourseId(Long courseId) {
        return scoreMapper.selectByCourseId(courseId);
    }

    @Override
    public Score addScore(Score score) {
        scoreMapper.insertScore(score);
        return score;
    }

    @Override
    public Score updateScore(Score score) {
        scoreMapper.updateScore(score);
        return score;
    }

    @Override
    public boolean deleteScore(Long id) {
        return scoreMapper.deleteScore(id) > 0;
    }

    @Override
    public int getScoreCount() {
        return scoreMapper.countAll();
    }
} 