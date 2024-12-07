The goal of this project is to simulate a simple to-do list management system. The system allows users to manage tasks by maintaining two key data structures. The queues represent the pending tasks that are still needed to do, the tasks are added to the queue and removed when the user processes them. The stacks represent completed tasks that have been done by the user. When a task is marked as completed it is pushed onto the stack. The the stack also allows the user to undo a complered task by moving it back to the queue. The state of the queue and stack is saved upond exiting the application and upon the program startup to ensure continuity across the sessions.

to run the program you compile g++ to_do_list.h to_do_list.cpp
then after type ./to_do_list

once the program runs it will give you a menu like such
1: Add a new task to the pending tasks queue.
2: View the next pending task in the queue.
3: Mark a task as completed (move it from the queue to the stack).
4: Undo a completed task (move it back from the stack to the queue).
5: Save the state to disk and exit the program.


The program uses two files for persistence:
queue.txt: which contains the pending tasks (queue).
stack.txt: which contains the completed tasks (stack).
These files are loaded automatically when the program starts and saved when the program exits