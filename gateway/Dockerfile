# 构建阶段
FROM maven:3.8.6-openjdk-17 AS build

# 配置Maven使用国内镜像源
RUN mkdir -p /root/.m2 && \
    echo '<?xml version="1.0" encoding="UTF-8"?>\
<settings xmlns="http://maven.apache.org/SETTINGS/1.0.0"\
          xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"\
          xsi:schemaLocation="http://maven.apache.org/SETTINGS/1.0.0 http://maven.apache.org/xsd/settings-1.0.0.xsd">\
    <mirrors>\
        <mirror>\
            <id>aliyun</id>\
            <name>Aliyun Maven</name>\
            <url>https://maven.aliyun.com/repository/public</url>\
            <mirrorOf>central</mirrorOf>\
        </mirror>\
    </mirrors>\
</settings>' > /root/.m2/settings.xml

WORKDIR /app

# 复制整个项目
COPY . .

# 构建应用
RUN mvn clean package -DskipTests -pl gateway -am

# 运行阶段
FROM openjdk:17-jre-slim

WORKDIR /app

# 复制构建的jar文件
COPY --from=build /app/gateway/target/*.jar app.jar

# 暴露端口
EXPOSE 9000

# 启动应用
CMD ["java", "-jar", "app.jar"] 