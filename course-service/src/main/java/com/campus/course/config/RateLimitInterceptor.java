package com.campus.course.config;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;

import java.util.concurrent.TimeUnit;

@Component
public class RateLimitInterceptor implements HandlerInterceptor {
    @Autowired
    private RedisTemplate<String, Object> redisTemplate;

    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        String path = request.getRequestURI();
        
        // 对选课接口进行限流
        if (path.contains("/select")) {
            String userInfo = (String) request.getAttribute("user");
            if (userInfo != null) {
                String[] arr = userInfo.split(":");
                String username = arr[0];
                String key = "rate_limit:select:" + username;
                
                // 每个用户每分钟最多选课5次
                Long count = redisTemplate.opsForValue().increment(key);
                if (count == 1) {
                    redisTemplate.expire(key, 1, TimeUnit.MINUTES);
                }
                
                if (count > 5) {
                    response.setStatus(429);
                    response.getWriter().write("选课过于频繁，请稍后再试");
                    return false;
                }
            }
        }
        
        return true;
    }
} 