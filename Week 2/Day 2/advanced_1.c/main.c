#include <stdio.h>

int main()
{
    int arr[50];
//    int n = sizeof(arr) / sizeof(arr[0]);
    int number = 0;
    int position = 0;

    // TODO: write a program wich asks for a number, that will be the real size of the array (50 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
	// print out the array
    // Then ask for a number, that will be the position, where you want the element to be deleted
    // handle the problem when trying to delete from invalid positions (e.g. negative number)
    // print out the the array after the deleting

    printf("Enter a number between 0 and 50: ");

    scanf("%d", &number);

        for (int i = 0; i < number; i++){
            arr[i] = i;

            printf("%d \n", arr[i]);
        }

    printf("Enter the element position to delete: ");

    scanf("%d", &position);

    if (position == number + 1 || position < 0){

        printf("Invalid position, enter position between 1 and %d", number);
    }
    else{

        for (int i = position - 1; i < number - 1; i++){

            arr[i] = arr[i + 1];
        }
        number--;
        }
        printf("\nElements of array after delete are: ");

        for (int i = 0; i < number; i++){

            printf("%d\t", arr[i]);
        }

    return 0;
}
