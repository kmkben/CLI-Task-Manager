#include "utils.h"


void inti_task_manager(TaskManager* task_manager)
{
    task_manager->tasks = NULL;
    task_manager->count = 0;
}

void add_task(TaskManager* task_manger, char* description, char* deadline)
{
}

void complete_task(TaskManager* task_manager, int task_id)
{
}

void delete_task(TaskManager* task_manager, int task_id)
{
}

void find_task(TaskManager* task_manager, char* keyword)
{
}

void list_tasks(TaskManager* task_manager)
{
}

void print_help()
{
    printf("\nCLI Task Manager based on cli mode\n");
                 
    printf("  add <task> <deadline>      Add the task <task> with the deadline <deadlin>\n");
    printf("  complete <task_id>         Mark a task that has id <task_id> as complete. When a task is done.\n");
    printf("  delete <task_id>           Delete the task that have id <task_id>.\n");
    printf("  exit                       Exit the program\n");
    printf("  find <task_id or keyword>  Find the task <task_id> or that contains the <keyword>\n");
    printf("  list                       List all the tasks\n");
    printf("  help or  h or   ?          To print the help page\n");
    printf("\n\n");
}
