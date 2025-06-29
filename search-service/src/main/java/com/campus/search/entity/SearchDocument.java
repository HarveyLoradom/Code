package com.campus.search.entity;

import com.fasterxml.jackson.annotation.JsonProperty;
import org.springframework.data.annotation.Id;
import org.springframework.data.elasticsearch.annotations.Document;
import org.springframework.data.elasticsearch.annotations.Field;
import org.springframework.data.elasticsearch.annotations.FieldType;

import java.util.Date;

@Document(indexName = "campus")
public class SearchDocument {
    
    @Id
    private String id;
    
    @Field(type = FieldType.Text, analyzer = "ik_max_word")
    @JsonProperty("title")
    private String title;
    
    @Field(type = FieldType.Text, analyzer = "ik_max_word")
    @JsonProperty("content")
    private String content;
    
    @Field(type = FieldType.Keyword)
    @JsonProperty("type")
    private String type;
    
    @Field(type = FieldType.Keyword)
    @JsonProperty("category")
    private String category;
    
    @Field(type = FieldType.Date)
    @JsonProperty("createTime")
    private Date createTime;
    
    // 构造函数
    public SearchDocument() {}
    
    public SearchDocument(String title, String content, String type, String category) {
        this.title = title;
        this.content = content;
        this.type = type;
        this.category = category;
        this.createTime = new Date();
    }
    
    // Getter和Setter方法
    public String getId() {
        return id;
    }
    
    public void setId(String id) {
        this.id = id;
    }
    
    public String getTitle() {
        return title;
    }
    
    public void setTitle(String title) {
        this.title = title;
    }
    
    public String getContent() {
        return content;
    }
    
    public void setContent(String content) {
        this.content = content;
    }
    
    public String getType() {
        return type;
    }
    
    public void setType(String type) {
        this.type = type;
    }
    
    public String getCategory() {
        return category;
    }
    
    public void setCategory(String category) {
        this.category = category;
    }
    
    public Date getCreateTime() {
        return createTime;
    }
    
    public void setCreateTime(Date createTime) {
        this.createTime = createTime;
    }
} 