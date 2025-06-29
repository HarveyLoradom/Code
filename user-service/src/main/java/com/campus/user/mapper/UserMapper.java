package com.campus.user.mapper;

import com.campus.user.entity.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import java.util.List;

@Mapper
public interface UserMapper {
    User selectByUsername(@Param("username") String username);
    int insertUser(User user);
    User selectById(@Param("id") Long id);
    List<User> selectByRole(@Param("role") String role);
    int countByRole(@Param("role") String role);
} 