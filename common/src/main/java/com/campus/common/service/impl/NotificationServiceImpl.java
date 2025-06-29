package com.campus.common.service.impl;

import com.campus.common.entity.NotificationMessage;
import com.campus.common.service.NotificationService;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.UUID;

@Service
public class NotificationServiceImpl implements NotificationService {
    @Autowired
    private RedisTemplate<String, Object> redisTemplate;
    
    @Autowired
    private ObjectMapper objectMapper;

    @Override
    public void sendNotification(NotificationMessage message) {
        try {
            message.setId(UUID.randomUUID().toString());
            message.setCreateTime(new Date());
            message.setRead(false);
            
            // 使用Redis发布订阅发送通知
            String channel = "notification:" + message.getTargetUser();
            redisTemplate.convertAndSend(channel, objectMapper.writeValueAsString(message));
            
            // 也可以保存到数据库
            System.out.println("发送通知: " + objectMapper.writeValueAsString(message));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void sendCourseSelectionNotification(String studentName, String courseName) {
        NotificationMessage message = new NotificationMessage();
        message.setType("course_selection");
        message.setTitle("选课成功通知");
        message.setContent("恭喜您成功选择了课程：" + courseName);
        message.setTargetUser(studentName);
        sendNotification(message);
    }

    @Override
    public void sendScorePublishedNotification(String studentName, String courseName, Double score) {
        NotificationMessage message = new NotificationMessage();
        message.setType("score_published");
        message.setTitle("成绩发布通知");
        message.setContent("您的课程" + courseName + "成绩已发布，成绩为：" + score);
        message.setTargetUser(studentName);
        sendNotification(message);
    }
} 