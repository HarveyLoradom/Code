package com.campus.user.controller;

import com.campus.user.entity.User;
import com.campus.user.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.RestTemplate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import javax.servlet.http.HttpServletRequest;

@RestController
@RequestMapping("/api/user")
public class UserController {
    @Autowired
    private UserService userService;
    
    @Autowired
    private RestTemplate restTemplate;
    
    private final BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();

    @PostMapping("/register")
    public Map<String, Object> register(@RequestBody User user) {
        Map<String, Object> res = new HashMap<>();
        if (userService.findByUsername(user.getUsername()) != null) {
            res.put("success", false);
            res.put("message", "用户名已存在");
            return res;
        }
        User newUser = userService.register(user);
        res.put("success", true);
        res.put("data", newUser);
        return res;
    }

    @PostMapping("/login")
    public Map<String, Object> login(@RequestBody Map<String, String> loginForm) {
        Map<String, Object> res = new HashMap<>();
        
        // 添加调试日志
        System.out.println("登录请求 - 用户名: " + loginForm.get("username"));
        System.out.println("登录请求 - 密码: " + loginForm.get("password"));
        
        User user = userService.login(loginForm.get("username"), loginForm.get("password"));
        if (user == null) {
            res.put("success", false);
            res.put("message", "用户名或密码错误");
            return res;
        }
        
        // 生成JWT token
        String token = com.campus.common.util.JwtUtil.generateToken(user.getUsername() + ":" + user.getRole());
        res.put("success", true);
        res.put("token", token);
        res.put("data", user);
        return res;
    }

    @GetMapping("/me")
    public Map<String, Object> getCurrentUser(HttpServletRequest request) {
        Map<String, Object> res = new HashMap<>();
        String userInfo = (String) request.getAttribute("user");
        if (userInfo == null) {
            res.put("success", false);
            res.put("message", "未登录");
            return res;
        }
        String[] arr = userInfo.split(":");
        res.put("success", true);
        res.put("username", arr[0]);
        res.put("role", arr.length > 1 ? arr[1] : "");
        return res;
    }

    @GetMapping("/teachers")
    public Map<String, Object> getTeachers() {
        Map<String, Object> res = new HashMap<>();
        List<User> teachers = userService.getUsersByRole("teacher");
        res.put("success", true);
        res.put("data", teachers);
        return res;
    }

    @GetMapping("/stats")
    public Map<String, Object> getStats(HttpServletRequest request) {
        Map<String, Object> res = new HashMap<>();
        try {
            // 获取学生总数
            int studentCount = userService.countByRole("student");
            
            // 获取JWT token用于跨服务调用
            String token = request.getHeader("Authorization");
            
            // 获取选课总数
            int selectionCount = 0;
            try {
                org.springframework.http.HttpHeaders headers = new org.springframework.http.HttpHeaders();
                if (token != null) {
                    headers.set("Authorization", token);
                }
                org.springframework.http.HttpEntity<String> entity = new org.springframework.http.HttpEntity<>(headers);
                
                Map<String, Object> selectionResponse = restTemplate.exchange(
                    "http://localhost:9002/api/course/selection/count", 
                    org.springframework.http.HttpMethod.GET, 
                    entity, 
                    Map.class
                ).getBody();
                
                if (selectionResponse != null && (Boolean) selectionResponse.get("success")) {
                    selectionCount = (Integer) selectionResponse.get("data");
                }
            } catch (Exception e) {
                System.err.println("获取选课总数失败: " + e.getMessage());
                e.printStackTrace();
            }
            
            // 获取成绩记录数
            int scoreCount = 0;
            try {
                org.springframework.http.HttpHeaders headers = new org.springframework.http.HttpHeaders();
                if (token != null) {
                    headers.set("Authorization", token);
                }
                org.springframework.http.HttpEntity<String> entity = new org.springframework.http.HttpEntity<>(headers);
                
                Map<String, Object> scoreResponse = restTemplate.exchange(
                    "http://localhost:9003/api/score/count", 
                    org.springframework.http.HttpMethod.GET, 
                    entity, 
                    Map.class
                ).getBody();
                
                if (scoreResponse != null && (Boolean) scoreResponse.get("success")) {
                    scoreCount = (Integer) scoreResponse.get("data");
                }
            } catch (Exception e) {
                System.err.println("获取成绩记录数失败: " + e.getMessage());
                e.printStackTrace();
            }
            
            res.put("success", true);
            Map<String, Object> data = new HashMap<>();
            data.put("studentCount", studentCount);
            data.put("selectionCount", selectionCount);
            data.put("scoreCount", scoreCount);
            res.put("data", data);
        } catch (Exception e) {
            res.put("success", false);
            res.put("message", "获取统计数据失败");
            e.printStackTrace();
        }
        return res;
    }

    // 测试接口：生成密码哈希
    @GetMapping("/test-password")
    public Map<String, Object> testPassword() {
        Map<String, Object> res = new HashMap<>();
        String testPassword = "123456";
        String hashedPassword = passwordEncoder.encode(testPassword);
        
        res.put("originalPassword", testPassword);
        res.put("hashedPassword", hashedPassword);
        res.put("matches", passwordEncoder.matches(testPassword, hashedPassword));
        
        // 测试数据库中的密码
        String dbPassword = "$2a$10$N.zmdr9k7uOCQb376NoUnuTJ8iAt6Z5EHsM8lE9lBOsl7iKTVEFDa";
        res.put("dbPasswordMatches", passwordEncoder.matches(testPassword, dbPassword));
        
        return res;
    }
} 