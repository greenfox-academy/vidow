#include <stdio.h>

int main()
{
    int arr[20];
    int freq[20];
    int number = 0;

    // TODO: write a program wich asks for a number, that will be the real size of the array (20 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
    // Finally print all unique elements in array

    printf("Enter a number between 0 and 20: ");

    scanf("%d", &number);

        for (int i = 0; i < number; i++){
            arr[i] = i;

            printf("%d \n", arr[i]);
        }
    return 0;
}
