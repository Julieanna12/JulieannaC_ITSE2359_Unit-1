#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <string>
#include "to_do_list.h"

using namespace std;

// Declare global data structures
queue<string> taskQueue;
stack<string> completedTasks;

// Load queue data from file
void loadQueueFromFile() {
    ifstream infile("queue.txt");
    string task;
    while (getline(infile, task)) {
        if (!task.empty()) {
            taskQueue.push(task);
        }
    }
    infile.close();
}

// Load stack data from file
void loadStackFromFile() {
    ifstream infile("stack.txt");
    string task;
    stack<string> tempStack;
    while (getline(infile, task)) {
        if (!task.empty()) {
            tempStack.push(task);
        }
    }

    while (!tempStack.empty()) {
        completedTasks.push(tempStack.top());
        tempStack.pop();
    }

    infile.close();
}

// Save queue to a file
void saveQueueToFile() {
    ofstream outfile("queue.txt");
    queue<string> tempQueue = taskQueue;
    while (!tempQueue.empty()) {
        outfile << tempQueue.front() << endl;
        tempQueue.pop();
    }
    outfile.close();
}

// Save stack to a file
void saveStackToFile() {
    ofstream outfile("stack.txt");
    stack<string> tempStack = completedTasks;
    while (!tempStack.empty()) {
        outfile << tempStack.top() << endl;
        tempStack.pop();
    }
    outfile.close();
}

int main() {
    int choice;

    loadQueueFromFile();
    loadStackFromFile();

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add a task\n";
        cout << "2. View next task\n";
        cout << "3. Complete a task\n";
        cout << "4. Undo a completed task\n";
        cout << "5. Save and exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                getline(cin, task);
                taskQueue.push(task);
                cout << "Task added.\n";
                break;
            }
            case 2: {
                if (!taskQueue.empty()) {
                    cout << "Next task: " << taskQueue.front() << endl;
                } else {
                    cout << "No pending tasks in the queue.\n";
                }
                break;
            }
            case 3: {
                if (!taskQueue.empty()) {
                    string task = taskQueue.front();
                    taskQueue.pop();
                    completedTasks.push(task);
                    cout << "Task completed: " << task << endl;
                } else {
                    cout << "No tasks to complete.\n";
                }
                break;
            }
            case 4: {
                if (!completedTasks.empty()) {
                    string task = completedTasks.top();
                    completedTasks.pop();
                    taskQueue.push(task);
                    cout << "Task moved back to the queue: " << task << endl;
                } else {
                    cout << "No tasks to undo.\n";
                }
                break;
            }
            case 5: {
                saveQueueToFile();
                saveStackToFile();
                cout << "State saved. Exiting program.\n";
                break;
            }
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
