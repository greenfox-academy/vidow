#include <stdio.h>
#include <stdlib.h>

/*
 * Create an array of 5 integers, fill it with random numbers.
 * Create an other of 7 integers.
 * Copy the contents of the first array into the second one in a way,
 * that the first and the last numbers of the second array are both 42,
 * and it contains all the elements of the first array.
 */

int main()
{
    int numbers1[5] = {3, 9, 12, 15, 18}; //Array with random numbers.
    int numbers2[7]; //Second array that will be the one where we copy the first array content.
    int a = 42; //Number which will be the first and last number of the second array.

    int lenght1 = sizeof(numbers1) / sizeof(0);
    int lenght2 = sizeof(numbers2) / sizeof(0);

    //For loop to copy the elements from "numbers1" array to "numbers2" array
    for (int i = 0; i < lenght1; i++) {
        //Numbers copied from numbers1 array to numbers2 array as follows:
        //Element of numbers1 array copied to numbers2 array second place
        numbers2[i + 1] = numbers1[i];

     }
    //For loop to set the first and last element of numbers2 array to value of "a" which is 42.
    for (int i = numbers1[i]; i < lenght2; i++) {

        numbers2[0] = a;
        numbers2[6] = a;

    printf("%d\n", numbers2[i]);

    }



    return 0;
}
