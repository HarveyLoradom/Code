package com.campus.score.mapper;

import com.campus.score.entity.Score;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import java.util.List;

@Mapper
public interface ScoreMapper {
    List<Score> selectAll();
    Score selectById(@Param("id") Long id);
    List<Score> selectByStudentId(@Param("studentId") Long studentId);
    List<Score> selectByCourseId(@Param("courseId") Long courseId);
    int insertScore(Score score);
    int updateScore(Score score);
    int deleteScore(@Param("id") Long id);
    int countAll();
} 