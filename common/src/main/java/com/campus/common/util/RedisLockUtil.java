package com.campus.common.util;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.data.redis.core.RedisTemplate;
import java.util.concurrent.TimeUnit;

@Component
public class RedisLockUtil {
    @Autowired
    private RedisTemplate<String, Object> redisTemplate;

    public boolean tryLock(String key, long timeout, TimeUnit unit) {
        return Boolean.TRUE.equals(redisTemplate.opsForValue().setIfAbsent(key, "1", timeout, unit));
    }

    public boolean releaseLock(String key) {
        return Boolean.TRUE.equals(redisTemplate.delete(key));
    }

    public boolean tryLock(String key) {
        return tryLock(key, 30, TimeUnit.SECONDS);
    }
} 