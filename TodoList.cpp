#include "TodoList.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

// Реализация структуры Task
Task::Task(const std::string& desc) 
    : description(desc), completed(false) {
    
    time_t now = time(0);
    tm* localTime = localtime(&now);
    
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M", localTime);
    createdAt = buffer;
}

// Реализация класса TodoList
string TodoList::getCurrentTime() const {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M", localTime);
    return buffer;
}

void TodoList::addTask(const string& taskDescription) {
    if (!taskDescription.empty()) {
        tasks.push_back(Task(taskDescription));
    }
}

bool TodoList::removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        return true;
    }
    return false;
}

bool TodoList::markTaskCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        return true;
    }
    return false;
}

void TodoList::clearAllTasks() {
    tasks.clear();
}

void TodoList::displayTasks(const vector<Task>& tasksToDisplay) const {
    if (tasksToDisplay.empty()) {
        cout << "📝 Задач нет" << endl;
        return;
    }
    
    cout << "\n--- Список задач ---" << endl;
    for (size_t i = 0; i < tasksToDisplay.size(); ++i) {
        const Task& task = tasksToDisplay[i];
        string status = task.completed ? "✅" : "⏳";
        cout << i + 1 << ". " << status << " " << task.description << endl;
        cout << "   📅 Создана: " << task.createdAt << endl;
        if (task.completed) {
            cout << "   🎉 Выполнена!" << endl;
        }
        cout << endl;
    }
}

void TodoList::displayAllTasks() const {
    displayTasks(tasks);
    
    if (!tasks.empty()) {
        cout << "📊 Статистика: " << getActiveCount() << " активных, " 
             << getCompletedCount() << " выполненных" << endl;
    }
}

void TodoList::displayActiveTasks() const {
    vector<Task> activeTasks;
    for (const auto& task : tasks) {
        if (!task.completed) {
            activeTasks.push_back(task);
        }
    }
    
    cout << "\n=== АКТИВНЫЕ ЗАДАЧИ ===" << endl;
    displayTasks(activeTasks);
}

void TodoList::displayCompletedTasks() const {
    vector<Task> completedTasks;
    for (const auto& task : tasks) {
        if (task.completed) {
            completedTasks.push_back(task);
        }
    }
    
    cout << "\n=== ВЫПОЛНЕННЫЕ ЗАДАЧИ ===" << endl;
    displayTasks(completedTasks);
}

int TodoList::getTaskCount() const {
    return tasks.size();
}

int TodoList::getCompletedCount() const {
    int count = 0;
    for (const auto& task : tasks) {
        if (task.completed) {
            count++;
        }
    }
    return count;
}

int TodoList::getActiveCount() const {
    return tasks.size() - getCompletedCount();
}