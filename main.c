#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


int main(int argc, char* argv[])
{
    printf("\n+--------------------------------------------------+\n");
    printf("|                                                  |\n");
    printf("|                 CLI Task Manager                 |\n");
    printf("|                                                  |\n");
    printf("+--------------------------------------------------+\n\n");

    char command[255];
    char task[100];
    char deadline[20];
    char str[255];

    TaskManager task_manager;
    init_task_manager(&task_manager);

    printf("Enter a command \n add <task> <deadline> | complete <id> | delete <id> | exit | find <id> | help | list \n\n ");

    while(1)
    {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "add", 3) == 0) 
        {
            sscanf(command, "add %[^\n]", str);
            int len_task = strlen(str) - 10;
            extractSubstring(str, 0, len_task - 1, task);
            extractSubstring(str, len_task, 10, deadline);
            
            if (isDateValid(deadline))
            {
                add_task(&task_manager, task, deadline);
                printf("Task added\n\n");
            }
            else
            {
                printf(" Error: Date invalid !\n\n");
            }
        } 
        else if (strncmp(command, "complete", 8) == 0) 
        {
            int taskId;
            
            sscanf(command, "complete %d", &taskId);

            get_task_manager_from_file(&task_manager);

            complete_task(&task_manager, taskId);

            write_task_manager_to_file(&task_manager);
        } 
        else if (strncmp(command, "delete", 6) == 0) 
        {
            int taskId;
            sscanf(command, "delete %d", &taskId);
            delete_task(&task_manager, taskId);
        } 
        else if (strncmp(command, "exit", 4) == 0) 
        {
            break;
        } 
        else if (strncmp(command, "find", 4) == 0)
        {
        }
        else if ((strncmp(command, "help", 4) == 0) || (strncmp(command, "h", 1) == 0) || (strncmp(command, "?", 1) == 0))
        {
        
            print_help();
        }
        else if (strncmp(command, "list", 4) == 0) 
        {
            get_task_manager_from_file(&task_manager);
            
            list_tasks(&task_manager);
        } 
        else 
        {
            printf("Error: %s: Command not found\n", command);
        }
    }
    

    return 0;
}
