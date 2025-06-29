package com.campus.user.service.impl;

import com.campus.user.entity.User;
import com.campus.user.mapper.UserMapper;
import com.campus.user.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    private UserMapper userMapper;
    
    private final BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();

    @Override
    public User findByUsername(String username) {
        return userMapper.selectByUsername(username);
    }

    @Override
    public User register(User user) {
        // 加密密码
        user.setPassword(passwordEncoder.encode(user.getPassword()));
        userMapper.insertUser(user);
        return user;
    }

    @Override
    public User login(String username, String password) {
        User user = userMapper.selectByUsername(username);
        System.out.println("查询到的用户: " + (user != null ? user.getUsername() : "null"));
        if (user != null) {
            System.out.println("数据库中的密码: " + user.getPassword());
            System.out.println("输入的密码: " + password);
            System.out.println("加密后的密码: " + passwordEncoder.encode(password));
            boolean matches = passwordEncoder.matches(password, user.getPassword());
            System.out.println("密码匹配结果: " + matches);
            if (matches) {
                return user;
            }
        }
        return null;
    }

    @Override
    public User findById(Long id) {
        return userMapper.selectById(id);
    }

    @Override
    public List<User> getUsersByRole(String role) {
        return userMapper.selectByRole(role);
    }

    @Override
    public int countByRole(String role) {
        return userMapper.countByRole(role);
    }
} 