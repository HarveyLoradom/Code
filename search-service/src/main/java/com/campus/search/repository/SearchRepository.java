package com.campus.search.repository;

import com.campus.search.entity.SearchDocument;
import org.springframework.data.elasticsearch.annotations.Query;
import org.springframework.data.elasticsearch.repository.ElasticsearchRepository;
import java.util.List;

public interface SearchRepository extends ElasticsearchRepository<SearchDocument, String> {
    List<SearchDocument> findByTitleContainingOrContentContaining(String title, String content);
    List<SearchDocument> findByType(String type);
    List<SearchDocument> findByTypeAndTitleContainingOrTypeAndContentContaining(String type1, String title, String type2, String content);

    @Query("{\"bool\": {\"should\": [" +
           "{\"match\": {\"title\": \"?0\"}}," +
           "{\"match\": {\"content\": \"?0\"}}" +
           "]}}")
    List<SearchDocument> searchByKeyword(String keyword);
} 