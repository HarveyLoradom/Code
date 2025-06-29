package com.campus.course.config;

import com.campus.common.util.JwtUtil;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;

@Component
public class JwtInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        String token = request.getHeader("Authorization");
        if (token != null && token.startsWith("Bearer ")) {
            token = token.substring(7);
            try {
                String subject = JwtUtil.parseToken(token);
                if (subject != null) {
                    request.setAttribute("user", subject);
                    return true;
                } else {
                    response.setStatus(401);
                    response.getWriter().write("无效或过期的Token");
                    return false;
                }
            } catch (Exception e) {
                response.setStatus(401);
                response.getWriter().write("无效或过期的Token");
                return false;
            }
        }
        response.setStatus(401);
        response.getWriter().write("未登录");
        return false;
    }
} 