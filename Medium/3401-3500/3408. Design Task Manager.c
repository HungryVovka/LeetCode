// 3408. Design Task Manager
//
// There is a task management system that allows users to manage their tasks, each associated with a priority. The system should 
// efficiently handle adding, modifying, executing, and removing tasks.
// 
// Implement the TaskManager class:
// 
// TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task-priority triples. Each 
// element in the input list is of the form [userId, taskId, priority], which adds a task to the specified user with the 
// given priority.
// 
// void add(int userId, int taskId, int priority) adds a task with the specified taskId and priority to the user 
// with userId. It is guaranteed that taskId does not exist in the system.
// 
// void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPriority. It is guaranteed 
// that taskId exists in the system.
// 
// void rmv(int taskId) removes the task identified by taskId from the system. It is guaranteed that taskId exists in the 
// system.
// 
// int execTop() executes the task with the highest priority across all users. If there are multiple tasks with the same highest 
// priority, execute the one with the highest taskId. After executing, the taskId is removed from the system. Return the 
// userId associated with the executed task. If no tasks are available, return -1.
// 
// Note that a user may be assigned multiple tasks.
// 
// Example 1:
// 
// Input:
// ["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
// [[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]
// 
// Output:
// [null, null, null, 3, null, null, 5]
// 
// Explanation
// 
// TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
// taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
// taskManager.edit(102, 8); // Updates priority of task 102 to 8.
// taskManager.execTop(); // return 3. Executes task 103 for User 3.
// taskManager.rmv(101); // Removes task 101 from the system.
// taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
// taskManager.execTop(); // return 5. Executes task 105 for User 5.
//  
// 
// Constraints:
// 
// 1 <= tasks.length <= 105
// 0 <= userId <= 105
// 0 <= taskId <= 105
// 0 <= priority <= 109
// 0 <= newPriority <= 109
// At most 2 * 105 calls will be made in total to add, edit, rmv, and execTop methods.
// The input is generated such that taskId will be valid.

#include <stdio.h>      // NULL
#include <stdlib.h>     // malloc, free

typedef struct{
    int user_id;
    int task_id;
    int priority;
} Task;

typedef struct{
    Task* heap;
    int* position;
    int size;
    int capacity;
} TaskManager;

int compare(Task a, Task b){
    if (a.priority != b.priority){
        return a.priority > b.priority;
    }
    return a.task_id > b.task_id;
}

void swap(TaskManager* manager, int i, int j){
    Task task_buffer;
    task_buffer = manager->heap[i];
    manager->heap[i] = manager->heap[j];
    manager->heap[j] = task_buffer;
    manager->position[manager->heap[i].task_id] = i;
    manager->position[manager->heap[j].task_id] = j;
}

void heapify_up(TaskManager* manager, int i){
    int parent;
    while(i > 0){
        parent = (i - 1) / 2;
        if (compare(manager->heap[parent], manager->heap[i])) break;
        swap(manager, parent, i);
        i = parent;
    }
}

void heapify_down(TaskManager* manager, int i){
    int left, right, largest;
    while (1){
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < manager->size &&
        !compare(manager->heap[largest], manager->heap[left])) largest = left;
        if (right < manager->size &&
        !compare(manager->heap[largest], manager->heap[right])) largest = right;
        if (largest == i) break;
        swap(manager, i, largest);
        i = largest;
    }
}

TaskManager* taskManagerCreate(int** tasks, int tasks_size, int* tasks_col_size){
    int i, user_id, task_id, priority;
    TaskManager* manager = (TaskManager*)malloc(sizeof(TaskManager));
    manager->capacity = 200000+5;
    manager->size = 0;
    manager->heap = (Task*)malloc(sizeof(Task) * manager->capacity);
    manager->position = (int*)malloc(sizeof(int) * 100001);
    for (i = 0; i <= 100000; i++){
        manager->position[i] = -1;
    }
    for (i = 0; i < tasks_size; i++){
        user_id = tasks[i][0];
        task_id = tasks[i][1];
        priority = tasks[i][2];
        manager->heap[manager->size].user_id = user_id;
        manager->heap[manager->size].task_id = task_id;
        manager->heap[manager->size].priority = priority;
        manager->position[task_id] = manager->size;
        heapify_up(manager, manager->size);
        manager->size++;
    }
    return manager;
}

void taskManagerAdd(TaskManager* manager, int user_id, 
                    int task_id, int priority){
    manager->heap[manager->size].user_id = user_id;
    manager->heap[manager->size].task_id = task_id;
    manager->heap[manager->size].priority = priority;
    manager->position[task_id] = manager->size;
    heapify_up(manager, manager->size);
    manager->size++;
}

void taskManagerEdit(TaskManager* manager, int task_id, int new_priority){
    int i;
    i = manager->position[task_id];
    if (i == -1) return;
    manager->heap[i].priority = new_priority;
    heapify_up(manager, i);
    heapify_down(manager, i);
}

void taskManagerRmv(TaskManager* manager, int task_id){
    int i;
    i = manager->position[task_id];
    if (i == -1) return;
    manager->position[task_id] = -1;
    manager->size--;
    if (i == manager->size) return;
    swap(manager, i, manager->size);
    heapify_up(manager, i);
    heapify_down(manager, i);
}

int taskManagerExecTop(TaskManager* manager){
    Task top_task;
    int user_id;
    if (manager->size == 0) return -1;
    top_task = manager->heap[0];
    user_id = top_task.user_id;
    taskManagerRmv(manager, top_task.task_id);
    return user_id;
}

void taskManagerFree(TaskManager* manager){
    free(manager->heap);
    free(manager->position);
    free(manager);
}

/**
 * Your TaskManager struct will be instantiated and called as such:
 * TaskManager* obj = taskManagerCreate(tasks, tasksSize, tasksColSize);
 * taskManagerAdd(obj, userId, taskId, priority);
 
 * taskManagerEdit(obj, taskId, newPriority);
 
 * taskManagerRmv(obj, taskId);
 
 * int param_4 = taskManagerExecTop(obj);
 
 * taskManagerFree(obj);
*/

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).