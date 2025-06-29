package com.campus.common.service;

import com.campus.common.entity.NotificationMessage;

public interface NotificationService {
    void sendNotification(NotificationMessage message);
    void sendCourseSelectionNotification(String studentName, String courseName);
    void sendScorePublishedNotification(String studentName, String courseName, Double score);
} 