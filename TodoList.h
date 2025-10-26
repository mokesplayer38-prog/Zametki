#ifndef TODOLIST_H
#define TODOLIST_H

#include <string>
#include <vector>

struct Task {
    std::string description;
    bool completed;
    std::string createdAt;
    
    Task(const std::string& desc);
};

class TodoList {
private:
    std::vector<Task> tasks;
    
    std::string getCurrentTime() const;
    void displayTasks(const std::vector<Task>& tasksToDisplay) const;
    
public:
    // Основные операции
    void addTask(const std::string& taskDescription);
    bool removeTask(int index);
    bool markTaskCompleted(int index);
    void clearAllTasks();
    
    // Отображение
    void displayAllTasks() const;
    void displayActiveTasks() const;
    void displayCompletedTasks() const;
    
    // Информация
    int getTaskCount() const;
    int getCompletedCount() const;
    int getActiveCount() const;
};

#endif