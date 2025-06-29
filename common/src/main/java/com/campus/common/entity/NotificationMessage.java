package com.campus.common.entity;

import lombok.Data;
import java.util.Date;

@Data
public class NotificationMessage {
    private String id;
    private String type; // course_selection, score_published, system_notice
    private String title;
    private String content;
    private String targetUser;
    private Date createTime;
    private boolean read;
} 