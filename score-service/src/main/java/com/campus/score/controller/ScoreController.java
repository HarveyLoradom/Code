package com.campus.score.controller;

import com.campus.score.entity.Score;
import com.campus.score.service.ScoreService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import com.campus.common.annotation.Log;

@RestController
@RequestMapping("/api/score")
public class ScoreController {
    @Autowired
    private ScoreService scoreService;

    @GetMapping("/list")
    public Map<String, Object> getAllScores() {
        Map<String, Object> res = new HashMap<>();
        List<Score> list = scoreService.getAllScores();
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @GetMapping("/{id}")
    public Map<String, Object> getScore(@PathVariable Long id) {
        Map<String, Object> res = new HashMap<>();
        Score score = scoreService.getScoreById(id);
        res.put("success", score != null);
        res.put("data", score);
        return res;
    }

    @GetMapping("/student/{studentId}")
    public Map<String, Object> getScoresByStudent(@PathVariable Long studentId) {
        Map<String, Object> res = new HashMap<>();
        List<Score> list = scoreService.getScoresByStudentId(studentId);
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @GetMapping("/course/{courseId}")
    public Map<String, Object> getScoresByCourse(@PathVariable Long courseId) {
        Map<String, Object> res = new HashMap<>();
        List<Score> list = scoreService.getScoresByCourseId(courseId);
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @PostMapping("/add")
    @Log(operation = "录入成绩", value = "教师录入学生成绩")
    public Map<String, Object> addScore(@RequestBody Score score) {
        Map<String, Object> res = new HashMap<>();
        Score newScore = scoreService.addScore(score);
        res.put("success", true);
        res.put("data", newScore);
        return res;
    }

    @PutMapping("/update")
    @Log(operation = "更新成绩", value = "教师更新学生成绩")
    public Map<String, Object> updateScore(@RequestBody Score score) {
        Map<String, Object> res = new HashMap<>();
        Score updated = scoreService.updateScore(score);
        res.put("success", true);
        res.put("data", updated);
        return res;
    }

    @DeleteMapping("/delete/{id}")
    @Log(operation = "删除成绩", value = "教师删除学生成绩")
    public Map<String, Object> deleteScore(@PathVariable Long id) {
        Map<String, Object> res = new HashMap<>();
        boolean deleted = scoreService.deleteScore(id);
        res.put("success", deleted);
        return res;
    }

    @GetMapping("/count")
    public Map<String, Object> getScoreCount() {
        Map<String, Object> res = new HashMap<>();
        try {
            int count = scoreService.getScoreCount();
            res.put("success", true);
            res.put("data", count);
        } catch (Exception e) {
            res.put("success", false);
            res.put("message", "获取成绩记录数失败");
        }
        return res;
    }
} 