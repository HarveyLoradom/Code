package com.campus.score;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication(scanBasePackages = {"com.campus.score", "com.campus.common"})
@EnableDiscoveryClient
public class ScoreServiceApplication {
    public static void main(String[] args) {
        SpringApplication.run(ScoreServiceApplication.class, args);
    }
} 