#include "utils.h"


void init_task_manager(TaskManager* task_manager)
{
    task_manager->tasks = NULL;
    task_manager->count = 0;
}

int getLongestTask(TaskManager* task_manager)
{
    int max = 0;

    for (int i = 0; i < task_manager->count; ++i)
    {
        if (max < strlen(task_manager->tasks[i].description))
        {
            max = strlen(task_manager->tasks[i].description);
        }
    }
    return max;
}

void write_task_to_file(Task* task, FILE* file)
{
    file = fopen(FILE_NAME, "a");

    if (file != NULL)
    {
        fprintf(file, "%d | %s | %s | %s\n", task->id, task->description, task->deadline, task->completed ? "Done" : "In Progress");
        fclose(file);
    }
    else
    {
        printf("Error: file tasks.txt not found\n");
    }
}

void write_task_manager_to_file(TaskManager* task_manager, FILE *file)
{
    file = fopen(FILE_NAME, "w");
    
    if (file != NULL)
    {
        for (int i = 0; i < task_manager->count; ++i)
        {
            fprintf(file, "%d | %s | %s | %s\n", task_manager->tasks[i].id, task_manager->tasks[i].description, task_manager->tasks[i].deadline, task_manager->tasks[i].completed ? "Done" : "In Progress");
        }
        fclose(file);
    }
    else
    {
        printf("Error: file tasks.txt not found\n");
    }
}

void get_task_manager_from_file(TaskManager* task_manager, FILE* file)
{
    init_task_manager(task_manager);

    file = fopen(FILE_NAME, "r");

    if (file != NULL)
    {
        int id;
        char description[100];
        char deadline[20];
        //char status[100];
        int completed;

        char line[1048];
        char* splited[10];
        char delimiter[] = " | ";
        char* ptr; 

        while(fgets(line, sizeof(line), file) != NULL)
        {
            ptr = strtok(line, delimiter);
            int i = 0;

            while (ptr != NULL)
            {
                splited[i] = ptr;
                i++;
                ptr = strtok(NULL, delimiter);
            }

            id = atoi(splited[0]);
            strcpy(description, splited[1]);
            strcpy(deadline, splited[2]);
            completed = (strcmp(splited[3], "Done") == 0);

            Task task;
            task.id = id;
            strcpy(task.description, description);
            strcpy(task.deadline, deadline);
            task.completed = completed;

            task_manager->tasks = realloc(task_manager->tasks, (task_manager->count + 1) * sizeof(Task));

            task_manager->tasks[task_manager->count] = task;
            task_manager->count++;        

        }
    }
    else
    {
        printf("Error: File tasks.txt not found !\n");
    }
}

void add_task(TaskManager* task_manager, char* description, char* deadline)
{
    printf("Deadline to add: %s\n", deadline);
    Task task;
    task.id = task_manager->count + 1;
    strcpy(task.description, description);
    strcpy(task.deadline, deadline);
    task.completed = 0;

    task_manager->tasks = realloc(task_manager->tasks, (task_manager->count + 1) * sizeof(Task));

    if (task_manager->tasks == NULL)
    {
        fprintf(stderr, "Error: Memory error: Impossible to alloc memory\n");
        exit(EXIT_FAILURE);
    }

    task_manager->tasks[task_manager->count] = task;
    task_manager->count++;
}

void complete_task(TaskManager* task_manager, int task_id)
{
    if (task_id >= 1 && task_id <= task_manager->count)
    {
        task_manager->tasks[task_id - 1].completed = 1;
    }
    else
    {
        printf("Error: task not found !\n");
    }
}

void delete_task(TaskManager* task_manager, int task_id)
{
    if (task_id >= 1 && task_id <= task_manager->count)
    {
        for (int i = task_id - 1; i < task_manager->count - 1; i++)
        {
            task_manager->tasks[i] = task_manager->tasks[i + 1];
        }
    }
    else
    {
        printf("Error: task not found !\n");
    }

}

void find_task(TaskManager* task_manager, char* keyword)
{
}

void list_tasks(TaskManager* task_manager)
{
    int maxLength = getLongestTask(task_manager);
    printf("m: %d", maxLength);
    char message_id[10] = " ID ";
    char message_task;
    int len = 0;
    int j = 0;
    printf("\nTasks list:\n\n");
    
    printf("+----+");
    for (int i = 0; i < maxLength + 6; ++i)
    {
        printf("-");
    }
    printf("+------------+----------+\n");
    printf("| ID |");
    for (int j = 0; j < (maxLength - 5) / 2 + 3; ++j)
    {
        printf(" ");
    }
    printf("TASKS");
    for (int i = 0; i < (maxLength - 5)/2 + 3; ++i)
    {
        printf(" ");
    }
    printf("|  DEADLINE  |  STATUS  |\n");
    printf("+----+");
    for (int i = 0; i < maxLength + 6; ++i)
    {
        printf("-");
    }
    printf("+------------+---------+\n");




    for (int i = 0; i < task_manager->count; i++)
    {
        int id = task_manager->tasks[i].id;

        if(id < 10)
        {
            printf("| %d  |", task_manager->tasks[i].id);
        }
        else
        {
            printf("| %d |", task_manager->tasks[i].id);
        }
        len = strlen(task_manager->tasks[i].description);
        int diff = maxLength - len;

        for (int j = 0; j < (diff / 2) + 3; ++j)
            printf(" ");
        printf("%s", task_manager->tasks[i].description);
        int limit = (diff % 2 == 0 ? (diff / 2) + 3 : (diff/2) + 4);
        for (int j = 0; j < limit; ++j)
        {
            printf(" ");
        }
        printf("| %s |", task_manager->tasks[i].deadline);
        
        if (task_manager->tasks[i].completed)
        {
            printf(" Done     |");
        }
        else
        {
            printf(" Not yet  |");
        }
        printf("\n");

        printf("+----+");
        for (int i = 0; i < maxLength + 6; ++i)
        {
            printf("-");
        }
        printf("+------------+----------+\n");
    }
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


void extractSubstring(char *inputString, int startIndex, int length, char *outputString) {
    int i, j;

    if (startIndex < 0 || startIndex >= strlen(inputString)) {
        printf("Indice de début invalide.\n");
        return;
    }

    for (i = startIndex, j = 0; j < length && inputString[i] != '\0'; ++i, ++j) {
        outputString[j] = inputString[i];
    }

    outputString[j] = '\0';
}


int isDateValid(char *date) {
    int day, month, year;
    char delim[] = "/";
	char* split[3];
    char dayStr[10], monthStr[10], yearStr[10];

    if(strlen(date) != 10)
	{
		printf("Incorrect format, error in length. (format: dd/mm/yyyy)\n");
        return 0;
	}

    if ((date[2] != '/') || (date[5] != '/'))
	{
		printf("Incorrect format (format: dd/mm/yyyy)\n");
        return 0;
	}

    char *ptr = strtok(date, delim);
	int i = 0;
			
    while (ptr != NULL)
	{
        split[i] = ptr;
		i++;
		ptr = strtok(NULL, delim);
	}

	day = atoi(split[0]);
	month = atoi(split[1]);
	year = atoi(split[2]);

    printf("date: %s and %d / %d / %d\n", date, day, month, year);
    
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) 
    {
        printf("Not interval\n");
        return 0; 
    }
    
    if (day < 10)
    {
        sprintf(dayStr, "0%d", day);
    }
    else
    {
        sprintf(dayStr, "%d", day);   

    }
    printf("Day : %s\n", dayStr);
    strcat(dayStr, "/");
    printf("Day : %s\n", dayStr);


    if (month < 10)
    {
        sprintf(monthStr, "0%d", month);
    }
    else
    {
        sprintf(monthStr, "%d", month);   

    }
    printf("Month : %s\n", monthStr);

    strcat(monthStr, "/");
    printf("Month : %s\n", monthStr);

    sprintf(yearStr, "%d", year);

    strcpy(date, "");
    printf("Date ..: %s\n", date);
    strcat(date, dayStr);
    printf("Date ..: %s\n", date);
    strcat(date, monthStr);
    printf("Date ..: %s\n", date);
    strcat(date, yearStr);
    printf("Date ..: %s\n", date);

    return 1;
}
