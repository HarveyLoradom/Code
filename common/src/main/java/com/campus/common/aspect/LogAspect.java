package com.campus.common.aspect;

import com.campus.common.annotation.Log;
import com.campus.common.entity.OperationLog;
import com.fasterxml.jackson.databind.ObjectMapper;
import javax.servlet.http.HttpServletRequest;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import java.util.Date;

@Aspect
@Component
public class LogAspect {
    @Autowired
    private ObjectMapper objectMapper;

    @Around("@annotation(log)")
    public Object around(ProceedingJoinPoint point, Log log) throws Throwable {
        long startTime = System.currentTimeMillis();
        Object result = null;
        try {
            result = point.proceed();
            return result;
        } finally {
            long endTime = System.currentTimeMillis();
            saveLog(point, log, endTime - startTime, result);
        }
    }

    private void saveLog(ProceedingJoinPoint point, Log log, long executionTime, Object result) {
        try {
            HttpServletRequest request = ((ServletRequestAttributes) RequestContextHolder.getRequestAttributes()).getRequest();
            OperationLog operationLog = new OperationLog();
            operationLog.setOperation(log.operation());
            operationLog.setMethod(point.getSignature().toString());
            operationLog.setParams(objectMapper.writeValueAsString(point.getArgs()));
            operationLog.setIp(getIpAddress(request));
            operationLog.setCreateTime(new Date());
            operationLog.setExecutionTime(executionTime);
            operationLog.setDescription(log.value());
            
            // 这里可以保存到数据库或发送到消息队列
            System.out.println("操作日志: " + objectMapper.writeValueAsString(operationLog));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private String getIpAddress(HttpServletRequest request) {
        String ip = request.getHeader("X-Forwarded-For");
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getHeader("Proxy-Client-IP");
        }
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getHeader("WL-Proxy-Client-IP");
        }
        if (ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
            ip = request.getRemoteAddr();
        }
        return ip;
    }
} 