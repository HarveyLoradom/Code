# 构建阶段
FROM maven:3.8.6-openjdk-17 AS build

WORKDIR /app

# 复制整个项目
COPY . .

# 构建应用
RUN mvn clean package -DskipTests -pl course-service -am

# 运行阶段
FROM openjdk:17-jre-slim

WORKDIR /app

# 复制构建的jar文件
COPY --from=build /app/course-service/target/*.jar app.jar

# 暴露端口
EXPOSE 9002

# 启动应用
CMD ["java", "-jar", "app.jar"] 