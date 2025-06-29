package com.campus.course.service.impl;

import com.campus.common.util.RedisLockUtil;
import com.campus.course.entity.Course;
import com.campus.course.entity.CourseSelection;
import com.campus.course.mapper.CourseSelectionMapper;
import com.campus.course.service.CourseSelectionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import java.util.List;
import com.campus.common.annotation.Log;
import com.campus.course.mapper.CourseMapper;
import com.campus.common.service.NotificationService;

@Service
public class CourseSelectionServiceImpl implements CourseSelectionService {
    @Autowired
    private CourseSelectionMapper selectionMapper;

    @Autowired
    private CourseMapper courseMapper;

    @Autowired
    private RedisLockUtil redisLockUtil;

    @Autowired
    private NotificationService notificationService;

    @Override
    public List<CourseSelection> getSelectionsByStudentId(Long studentId) {
        return selectionMapper.selectByStudentId(studentId);
    }

    @Override
    public List<CourseSelection> getSelectionsByCourseId(Long courseId) {
        return selectionMapper.selectByCourseId(courseId);
    }

    @Override
    @Transactional
    @Log(operation = "选课", value = "学生选课操作")
    public boolean selectCourse(Long studentId, Long courseId) {
        String lockKey = "course_selection:" + courseId;
        
        if (!redisLockUtil.tryLock(lockKey)) {
            throw new RuntimeException("课程正在被其他用户选择，请稍后再试");
        }
        
        try {
            // 检查课程容量
            Course course = courseMapper.selectById(courseId);
            if (course == null) {
                throw new RuntimeException("课程不存在");
            }
            if (course.getSelectedCount() >= course.getCapacity()) {
                throw new RuntimeException("课程已满");
            }
            
            // 检查是否已选
            List<CourseSelection> existing = selectionMapper.selectByStudentId(studentId);
            for (CourseSelection selection : existing) {
                if (selection.getCourseId().equals(courseId)) {
                    throw new RuntimeException("已选择该课程");
                }
            }
            
            // 执行选课
            CourseSelection selection = new CourseSelection();
            selection.setStudentId(studentId);
            selection.setCourseId(courseId);
            boolean success = selectionMapper.insertSelection(selection) > 0;
            
            if (success) {
                // 更新课程已选人数
                course.setSelectedCount(course.getSelectedCount() + 1);
                courseMapper.updateCourse(course);
                
                // 发送选课成功通知
                notificationService.sendCourseSelectionNotification("student", course.getCourseName());
            }
            
            return success;
        } finally {
            redisLockUtil.releaseLock(lockKey);
        }
    }

    @Override
    @Transactional
    @Log(operation = "退课", value = "学生退课操作")
    public boolean dropCourse(Long studentId, Long courseId) {
        return selectionMapper.deleteSelection(studentId, courseId) > 0;
    }

    @Override
    public int getSelectionCount() {
        return selectionMapper.countAll();
    }

    @Override
    public void deleteSelection(Long id) {
        // 先查询选课记录获取studentId和courseId
        CourseSelection selection = selectionMapper.selectById(id);
        if (selection != null) {
            selectionMapper.deleteSelection(selection.getStudentId(), selection.getCourseId());
        }
    }
} 