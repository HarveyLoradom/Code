package com.campus.course.controller;

import com.campus.course.entity.Course;
import com.campus.course.service.CourseService;
import com.campus.common.annotation.Log;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/api/course")
public class CourseController {
    @Autowired
    private CourseService courseService;

    @GetMapping("/{id}")
    public Map<String, Object> getCourse(@PathVariable Long id) {
        Map<String, Object> res = new HashMap<>();
        Course course = courseService.getCourseById(id);
        res.put("success", course != null);
        res.put("data", course);
        return res;
    }

    @GetMapping("/list")
    public Map<String, Object> getAllCourses() {
        Map<String, Object> res = new HashMap<>();
        List<Course> list = courseService.getAllCourses();
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @PostMapping("/add")
    @Log(operation = "添加课程", value = "管理员或教师添加课程")
    public Map<String, Object> addCourse(@RequestBody Course course) {
        Map<String, Object> res = new HashMap<>();
        Course newCourse = courseService.addCourse(course);
        res.put("success", true);
        res.put("data", newCourse);
        return res;
    }

    @PutMapping("/update")
    @Log(operation = "更新课程", value = "管理员或教师更新课程信息")
    public Map<String, Object> updateCourse(@RequestBody Course course) {
        Map<String, Object> res = new HashMap<>();
        Course updated = courseService.updateCourse(course);
        res.put("success", true);
        res.put("data", updated);
        return res;
    }

    @DeleteMapping("/delete/{id}")
    @Log(operation = "删除课程", value = "管理员或教师删除课程")
    public Map<String, Object> deleteCourse(@PathVariable Long id) {
        Map<String, Object> res = new HashMap<>();
        boolean deleted = courseService.deleteCourse(id);
        res.put("success", deleted);
        return res;
    }
} 