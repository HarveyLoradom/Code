package com.campus.common.api;

import lombok.Data;

@Data
public class ApiResponse<T> {
    private boolean success;
    private int code;
    private String message;
    private T data;

    public static <T> ApiResponse<T> ok(T data) {
        ApiResponse<T> res = new ApiResponse<>();
        res.setSuccess(true);
        res.setCode(200);
        res.setMessage("操作成功");
        res.setData(data);
        return res;
    }

    public static <T> ApiResponse<T> fail(String message) {
        ApiResponse<T> res = new ApiResponse<>();
        res.setSuccess(false);
        res.setCode(500);
        res.setMessage(message);
        return res;
    }

    public static <T> ApiResponse<T> fail(int code, String message) {
        ApiResponse<T> res = new ApiResponse<>();
        res.setSuccess(false);
        res.setCode(code);
        res.setMessage(message);
        return res;
    }
} 