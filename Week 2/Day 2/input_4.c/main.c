#include <stdio.h>
#include <string.h>

int main()
{
    number();
    number1();

    //write a void function which asks for a number with scanf and print it out with printf, then asks for a name with gets, and print it out with puts
    //you will notice something is wrong
    //try to solve the problem

return(0);
}

void number(){

    char name;

    printf("Type one character here: ");

    scanf("%c", &name);

    printf("You have entered %c\n", name);
    getchar(); // or fflush(stdin);

}

void number1(){

    char name[255];

    printf("Enter your name here: ");
    gets(name);
    printf("Your name is: ");
    puts(name);
    getch();

}
