#ifndef UTILS_CLI_TASK_MANAGER_H
#define UTILS_CLI_TASK_MANAGER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define FILE_NAME "tasks.txt"

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
int getLongestTask(TaskManager*);

void write_task_manager_to_file(TaskManager*);
void get_task_manager_from_file(TaskManager*);

void add_task(TaskManager*, char*, char*);
void complete_task(TaskManager*, int);
void delete_task(TaskManager*, int);
void find_task(TaskManager*, char*);
void list_tasks(TaskManager*);

void write_task_to_file(Task*);

void print_help();
void extractSubstring(char *inputString, int startIndex, int length, char *outputString);
int isDateValid(char*);
void trim(char*);


#endif   //UTILS_CLI_TASk_MANAGER_H
