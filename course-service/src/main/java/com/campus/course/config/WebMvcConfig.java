package com.campus.course.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.CorsRegistry;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

@Configuration
public class WebMvcConfig implements WebMvcConfigurer {
    @Autowired
    private JwtInterceptor jwtInterceptor;

    @Autowired
    private RoleInterceptor roleInterceptor;

    @Autowired
    private RateLimitInterceptor rateLimitInterceptor;

    @Override
    public void addCorsMappings(CorsRegistry registry) {
        registry.addMapping("/**")
                .allowedOriginPatterns("*")
                .allowedMethods("GET", "POST", "PUT", "DELETE", "OPTIONS")
                .allowedHeaders("*")
                .allowCredentials(true)
                .maxAge(3600);
    }

    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        registry.addInterceptor(jwtInterceptor)
                .addPathPatterns("/api/course/**")
                .excludePathPatterns("/api/course/list", "/api/course/{id}", "/api/course/selection/count");
        registry.addInterceptor(roleInterceptor)
                .addPathPatterns("/api/course/**")
                .excludePathPatterns("/api/course/list", "/api/course/{id}", "/api/course/selection/count");
        registry.addInterceptor(rateLimitInterceptor)
                .addPathPatterns("/api/course/**");
    }
} 