package com.campus.course.controller;

import com.campus.course.entity.CourseSelection;
import com.campus.course.service.CourseSelectionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/api/course/selection")
public class CourseSelectionController {
    @Autowired
    private CourseSelectionService selectionService;

    @GetMapping("/student/{studentId}")
    public Map<String, Object> getSelectionsByStudent(@PathVariable Long studentId) {
        Map<String, Object> res = new HashMap<>();
        List<CourseSelection> list = selectionService.getSelectionsByStudentId(studentId);
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @GetMapping("/course/{courseId}")
    public Map<String, Object> getSelectionsByCourse(@PathVariable Long courseId) {
        Map<String, Object> res = new HashMap<>();
        List<CourseSelection> list = selectionService.getSelectionsByCourseId(courseId);
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @PostMapping("/select")
    public Map<String, Object> selectCourse(@RequestBody Map<String, Long> req) {
        Map<String, Object> res = new HashMap<>();
        boolean ok = selectionService.selectCourse(req.get("studentId"), req.get("courseId"));
        res.put("success", ok);
        return res;
    }

    @PostMapping("/drop")
    public Map<String, Object> dropCourse(@RequestBody Map<String, Long> req) {
        Map<String, Object> res = new HashMap<>();
        boolean ok = selectionService.dropCourse(req.get("studentId"), req.get("courseId"));
        res.put("success", ok);
        return res;
    }

    @DeleteMapping("/{id}")
    public Map<String, Object> deleteSelection(@PathVariable Long id) {
        Map<String, Object> res = new HashMap<>();
        selectionService.deleteSelection(id);
        res.put("success", true);
        return res;
    }

    @GetMapping("/count")
    public Map<String, Object> getSelectionCount() {
        Map<String, Object> res = new HashMap<>();
        try {
            int count = selectionService.getSelectionCount();
            res.put("success", true);
            res.put("data", count);
        } catch (Exception e) {
            res.put("success", false);
            res.put("message", "获取选课总数失败");
        }
        return res;
    }
} 