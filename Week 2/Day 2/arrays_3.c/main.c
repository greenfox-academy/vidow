#include <stdio.h>

int main() {
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

	//TODO:
    // Print out the content of the arrays

    printf("%d\n", sizeof(int_array));
    printf("%d\n", sizeof(float_array));

    for (int i = 0; i < 5; i++){
        printf("%d ", int_array[i]);
    }
    //printf("%d\n", int_array);
    //printf("%d\n", float_array);

        printf("\n");

    for (int j = 0; j < 5; j++){
        printf("%.2f ", float_array[j]);
    }

    return 0;
}
