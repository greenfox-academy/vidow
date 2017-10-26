#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int task_num = 0;
char buffer[100];
char getinput[100];

typedef struct store {

    char task[100];
    unsigned char prio;
    unsigned char checked;

}store;

store todos[100];

void commands(store *input);

int main()
{


    main_menu();

    commands(todos);

    writer(todos);

    return 0;
}
//Function for the main menu.
void main_menu()
{
    printf( "           Todo application\n"
            "========================================\n"
            "Commands:\n"
            "-a   Adds a new task\n"
            "-wr  Write current todos to file\n"
            "-rd  Read todos from a file\n"
            "-l   Lists all the tasks\n"
            "-e   Empty the list\n"
            "-rm  Removes a task\n"
            "-c   Completes a task\n"
            "-p   Add priority to a task\n"
            "-lp  Lists all the tasks by priority\n");

    while (getchar() != '\n');{
        clear();
    }
}
//Function for the commands in main menu.
void commands(store *input)
{

    while (strcmp(getinput, "exit") != 0) {
        gets(getinput);

        if (strcmp(getinput, "-a") == 0) {
            printf("Please add a new task: \n");
            gets(input[task_num].task);
            task_num++;
        }
        if (strcmp(getinput, "-wr") == 0) {
            writer(todos);
        }
        if (strcmp(getinput, "-rd") == 0) {
            lister(todos);
        }
        if (strcmp(getinput, "exit") == 0) {
            exit(0);
        }
    }
}
//Function to store the entered task

//Function to clear the screen
void clear()
{
    system("cls");
}

void writer(store *input)
{
    FILE *fp;

    fp = fopen("todos.txt", "w+");
    for (int i = 0; i < task_num; i++) {

    fprintf(fp, "%s\n", input[i].task);
    }
    fclose(fp);
}

void lister(store *input)
{
    FILE *fp;

    fp = fopen("todos.txt", "r");

    while (fgets(input[task_num].task, 100, fp) != NULL) {

//        for (int i = 0; i < task_num; i++) {

        }
        printf("%s", input[task_num].task);
 //   }
    fclose(fp);

}