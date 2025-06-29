package com.campus.course.config;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;

@Component
public class RoleInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        String userInfo = (String) request.getAttribute("user");
        if (userInfo == null) {
            response.setStatus(401);
            response.getWriter().write("未登录");
            return false;
        }
        
        String[] arr = userInfo.split(":");
        String role = arr.length > 1 ? arr[1] : "";
        String path = request.getRequestURI();
        
        // 增删改课程需要管理员或教师权限
        if ((path.contains("/add") || path.contains("/update") || path.contains("/delete")) && 
            !"admin".equals(role) && !"teacher".equals(role)) {
            response.setStatus(403);
            response.getWriter().write("权限不足");
            return false;
        }
        
        return true;
    }
} 