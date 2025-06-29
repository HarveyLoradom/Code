package com.campus.search.service.impl;

import com.campus.search.entity.SearchDocument;
import com.campus.search.repository.SearchRepository;
import com.campus.search.service.SearchService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class SearchServiceImpl implements SearchService {
    
    @Autowired
    private SearchRepository searchRepository;
    
    @Override
    public List<SearchDocument> search(String keyword) {
        return searchRepository.searchByKeyword(keyword);
    }
    
    @Override
    public List<SearchDocument> searchByType(String keyword, String type) {
        return searchRepository.findByTypeAndTitleContainingOrTypeAndContentContaining(type, keyword, type, keyword);
    }
    
    @Override
    public SearchDocument save(SearchDocument document) {
        return searchRepository.save(document);
    }
    
    @Override
    public void delete(String id) {
        searchRepository.deleteById(id);
    }
} 