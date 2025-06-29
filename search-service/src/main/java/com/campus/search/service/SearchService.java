package com.campus.search.service;

import com.campus.search.entity.SearchDocument;
import java.util.List;

public interface SearchService {
    List<SearchDocument> search(String keyword);
    List<SearchDocument> searchByType(String keyword, String type);
    SearchDocument save(SearchDocument document);
    void delete(String id);
} 