#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


int main(int argc, char* argv[])
{
    printf("\n|--------------------------------------------------|\n");
    printf("|                                                  |\n");
    printf("|                 CLI Task Manager                 |\n");
    printf("|                                                  |\n");
    printf("|--------------------------------------------------|\n\n");

    char command[255];

    printf("Enter a command \n add <task> <deadline> | complete <id> | delete <id> | exit | find <id> | help | list \n\n ");

    while(1)
    {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "add", 3) == 0) 
        {
            
            //sscanf(command, "add %99s %19s", task, deadline);
            
            //addTask(&manager, task, deadline);
        } 
        else if (strncmp(command, "complete", 8) == 0) 
        {
            int taskId;
            
            //sscanf(command, "complete %d", &taskId);
            //completeTask(&manager, taskId);
        } 
        else if (strncmp(command, "delete", 6) == 0) 
        {
            int taskId;
            //sscanf(command, "delete %d", &taskId);
            //deleteTask(&manager, taskId);
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
            
            //listTasks(&manager);
        } 
        else {
            printf("Error: %s: Command not found\n", command);
        }
    }
    

    return 0;
}
