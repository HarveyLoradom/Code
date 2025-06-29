package com.campus.common.util;

import java.util.Date;
import java.util.Base64;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class JwtUtil {
    private static final String SECRET = "campusSecretKey";
    private static final long EXPIRATION = 1000 * 60 * 60 * 24; // 1天

    public static String generateToken(String subject) {
        try {
            // 创建简单的JWT格式：header.payload.signature
            String header = "{\"alg\":\"HS256\",\"typ\":\"JWT\"}";
            String payload = "{\"sub\":\"" + subject + "\",\"iat\":" + System.currentTimeMillis() + 
                           ",\"exp\":" + (System.currentTimeMillis() + EXPIRATION) + "}";
            
            // Base64编码
            String encodedHeader = Base64.getUrlEncoder().withoutPadding().encodeToString(header.getBytes());
            String encodedPayload = Base64.getUrlEncoder().withoutPadding().encodeToString(payload.getBytes());
            
            // 创建签名
            String data = encodedHeader + "." + encodedPayload;
            String signature = createSignature(data, SECRET);
            
            return data + "." + signature;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public static String parseToken(String token) {
        try {
            String[] parts = token.split("\\.");
            if (parts.length != 3) {
                return null;
            }
            
            // 验证签名
            String data = parts[0] + "." + parts[1];
            String expectedSignature = createSignature(data, SECRET);
            if (!expectedSignature.equals(parts[2])) {
                return null;
            }
            
            // 解析payload
            String payload = new String(Base64.getUrlDecoder().decode(parts[1]));
            // 简单提取subject，实际项目中应该用JSON解析
            if (payload.contains("\"sub\":")) {
                int start = payload.indexOf("\"sub\":\"") + 7;
                int end = payload.indexOf("\"", start);
                return payload.substring(start, end);
            }
            
            return null;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
    
    private static String createSignature(String data, String secret) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            String input = data + secret;
            byte[] hash = md.digest(input.getBytes());
            return Base64.getUrlEncoder().withoutPadding().encodeToString(hash);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return "";
        }
    }
} 