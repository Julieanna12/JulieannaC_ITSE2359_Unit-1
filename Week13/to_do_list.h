#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <queue>
#include <stack>
#include <string>

extern std::queue<std::string> taskQueue;
extern std::stack<std::string> completedTasks;

// Function declarations
void loadQueueFromFile();
void loadStackFromFile();
void saveQueueToFile();
void saveStackToFile();

#endif
