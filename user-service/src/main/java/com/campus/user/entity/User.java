package com.campus.user.entity;

import lombok.Data;
import java.util.Date;

@Data
public class User {
    private Long id;
    private String username;
    private String password;
    private String realName;
    private String role; // student, teacher, admin
    private String email;
    private String phone;
    private Date createdAt;
} 