#include <stdio.h>

int main() {
    int number = 1234;
    //TODO:
    // print the memory address of the variable

    int *a = 0;
    a = &number;
    //Printing memory address of the variable:
    printf("The memory address of 'number' is %p.\n", a);
    //or:
    printf("The memory address of 'number' is %p.\n", &number);
    //Printing the value of the variable:
    printf("The value of number is %d.\n", *a);

    return 0;
}
