#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);

int main() {
    vector<string> tasks;  // Vector to store tasks
    int choice;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after the choice input

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
}

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task description: ";
    getline(cin, task);  // Use getline to allow spaces in task description
    tasks.push_back(task);
    cout << "Task added." << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show." << endl;
    } else {
        cout << "\nTasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void deleteTask(vector<string>& tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        int taskNum;
        cout << "Enter the number of the task to delete: ";
        cin >> taskNum;
        cin.ignore();  // To ignore the newline character after the task number input

        if (taskNum >= 1 && taskNum <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNum - 1);
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}
