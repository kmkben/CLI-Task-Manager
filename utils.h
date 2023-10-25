#ifndef UTILS_CLI_TASK_MANAGER_H
#define UTILS_CLI_TASK_MANAGER_H


#include <stdio.h>

typedef struct Task Task;
struct Task
{
    int id;
    char description[100];
    char deadline[20];
    int completed;
};


typedef struct TaskManager TaskManager;
struct TaskManager
{
    Task* tasks;
    int count;
};


void init_task_manager(TaskManager*);


void addTask(TaskManager*, char*, char*);
void complete_task(TaskManager*, int);
void delete_task(TaskManager*, int);
void find_task(TaskManager*, char*);
void list_tasks(TaskManager*)

void print_help();


#endif   //UTILS_CLI_TASk_MANAGER_H
