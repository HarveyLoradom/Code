package com.campus.search.controller;

import com.campus.search.entity.SearchDocument;
import com.campus.search.service.SearchService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/api/search")
public class SearchController {
    @Autowired
    private SearchService searchService;

    @GetMapping("/keyword")
    public Map<String, Object> search(@RequestParam String keyword) {
        Map<String, Object> res = new HashMap<>();
        List<SearchDocument> list = searchService.search(keyword);
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @GetMapping("/type")
    public Map<String, Object> searchByType(@RequestParam String keyword, @RequestParam String type) {
        Map<String, Object> res = new HashMap<>();
        List<SearchDocument> list = searchService.searchByType(keyword, type);
        res.put("success", true);
        res.put("data", list);
        return res;
    }

    @PostMapping("/index")
    public Map<String, Object> index(@RequestBody SearchDocument document) {
        Map<String, Object> res = new HashMap<>();
        SearchDocument saved = searchService.save(document);
        res.put("success", true);
        res.put("data", saved);
        return res;
    }

    @DeleteMapping("/{id}")
    public Map<String, Object> delete(@PathVariable String id) {
        Map<String, Object> res = new HashMap<>();
        searchService.delete(id);
        res.put("success", true);
        return res;
    }
} 