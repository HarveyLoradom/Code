package com.campus.user.service;

import com.campus.user.entity.User;
import java.util.List;

public interface UserService {
    User findByUsername(String username);
    User register(User user);
    User login(String username, String password);
    User findById(Long id);
    List<User> getUsersByRole(String role);
    int countByRole(String role);
} 