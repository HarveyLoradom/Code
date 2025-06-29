package com.campus.common.entity;

import lombok.Data;
import java.util.Date;

@Data
public class OperationLog {
    private Long id;
    private String username;
    private String operation;
    private String method;
    private String params;
    private String ip;
    private Date createTime;
    private Long executionTime;
    private String description;
} 