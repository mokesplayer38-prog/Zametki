#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include "TodoList.h"

using namespace std;

void displayMenu() {
    cout << "\n=== УМНЫЙ СПИСОК ДЕЛ ===" << endl;
    cout << "1. Показать все задачи" << endl;
    cout << "2. Добавить задачу" << endl;
    cout << "3. Отметить как выполненную" << endl;
    cout << "4. Удалить задачу" << endl;
    cout << "5. Показать активные задачи" << endl;
    cout << "6. Показать выполненные задачи" << endl;
    cout << "7. Очистить все задачи" << endl;
    cout << "8. Выйти" << endl;
    cout << "Выберите действие: ";
}

int main() {
    TodoList todoList;
    int choice;
    
    cout << "Добро пожаловать в Умный список дел!" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        // Очистка буфера ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: {
                todoList.displayAllTasks();
                break;
            }
            case 2: {
                string task;
                cout << "Введите новую задачу: ";
                getline(cin, task);
                todoList.addTask(task);
                cout << "✅ Задача добавлена!" << endl;
                break;
            }
            case 3: {
                todoList.displayAllTasks();
                if (todoList.getTaskCount() > 0) {
                    int index;
                    cout << "Введите номер задачи для отметки: ";
                    cin >> index;
                    if (todoList.markTaskCompleted(index - 1)) {
                        cout << "✅ Задача отмечена как выполненная!" << endl;
                    } else {
                        cout << "❌ Неверный номер задачи!" << endl;
                    }
                }
                break;
            }
            case 4: {
                todoList.displayAllTasks();
                if (todoList.getTaskCount() > 0) {
                    int index;
                    cout << "Введите номер задачи для удаления: ";
                    cin >> index;
                    if (todoList.removeTask(index - 1)) {
                        cout << "✅ Задача удалена!" << endl;
                    } else {
                        cout << "❌ Неверный номер задачи!" << endl;
                    }
                }
                break;
            }
            case 5: {
                todoList.displayActiveTasks();
                break;
            }
            case 6: {
                todoList.displayCompletedTasks();
                break;
            }
            case 7: {
                char confirm;
                cout << "Вы уверены? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    todoList.clearAllTasks();
                    cout << "✅ Все задачи удалены!" << endl;
                }
                break;
            }
            case 8: {
                cout << "До свидания! Хорошего дня! 👋" << endl;
                break;
            }
            default: {
                cout << "❌ Неверный выбор! Попробуйте снова." << endl;
                break;
            }
        }
        
    } while (choice != 8);
    
    return 0;
}