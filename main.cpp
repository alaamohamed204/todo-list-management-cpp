#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>
using namespace std;

// Task struct to represent a task
struct Task {
    string name;
    string description;
    string dueDate;
    bool completed;

    // Mark the task as completed
    void markCompleted() { completed = true; }

    // Display task details
    void display() {
        cout << name << " (" << (completed ? "Completed" : "Pending")
            << ") - Due: " << dueDate << "\n   Description: " << description << endl;
    }
};

// ToDoList struct to manage a list of tasks
struct ToDoList {
    vector<Task> tasks;

        // Clear screen and set text color
        void clearScreen() {
            system("color ED");  // Set text color to yellow (E) and background to black (0)
        }

    // Display the menu
    void displayMenu() {
        clearScreen();
        cout << "\t\t\t***********************************************************************" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t*                      WELCOME TO Your ToDo List                      *" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;
        cout << "1. Add Task\n2. Delete Task\n3. Display Tasks\n4. Mark Task as Completed\n5. Edit Task\n6. Exit\n";
    }

    // Add a new task
    void addTask() {
        Task newTask;
        cin.ignore();
        cout << "Enter task name: "; getline(cin, newTask.name);
        cout << "Enter task description: "; getline(cin, newTask.description);
        cout << "Enter task due date (YYYY-MM-DD): "; getline(cin, newTask.dueDate);
        newTask.completed = false; // Initialize completed to false
        tasks.push_back(newTask);
        cout << "Task added successfully!" << endl;
        system("pause");  // Pause to allow user to see the message
        system("cls");   // Close the console window
    }

    // Delete a task
    void deleteTask() {
        if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        displayTasks();
        cout << "Enter the task number to delete: ";
        int taskNumber; cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
        system("pause");  // Pause to allow user to see the message
        system("cls");   // Close the console window
    }

    // Display all tasks
    void displayTasks() {

        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].display();
        }
        system("pause");  // Pause to allow user to see the message
        system("cls");   // Close the console window
    }

    // Mark a task as completed
    void markTaskCompleted() {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!" << endl;
            return;
        }
        displayTasks();
        cout << "Enter the task number to mark as completed: ";
        int taskNumber; cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
        system("pause");  // Pause to allow user to see the message
        system("cls");   // Close the console window
    }

    // Edit a task
    void editTask() {
        if (tasks.empty()) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        displayTasks();
        cout << "Enter the task number to edit: ";
        int taskNumber; cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            Task& task = tasks[taskNumber - 1];
            cin.ignore();
            cout << "Enter new task name (current: " << task.name << "): "; getline(cin, task.name);
            cout << "Enter new task description (current: " << task.description << "): "; getline(cin, task.description);
            cout << "Enter new task due date (current: " << task.dueDate << "): "; getline(cin, task.dueDate);
            cout << "Task updated successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
        system("pause");  // Pause to allow user to see the message
        system("cls");   // Close the console window
    }

    // Run the to-do list application
    void run() {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1: addTask(); break;
            case 2: deleteTask(); break;
            case 3: displayTasks(); break;
            case 4: markTaskCompleted(); break;
            case 5: editTask(); break;
            case 6: cout << "Exiting program. Bye!" << endl; break;
            default: cout << "Invalid choice. Please try again!" << endl;
            }
        } while (choice != 6);
    }
};

// Main function
int main() {
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
