#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	float val;
	char str[5];
	strcpy(str, "3.14");

	printf("Value pf PI as string = %s.\nValue of PI as float is = %.2f.", str, atof(str));

	//TODO: print out the value of pi, first as a string, then a float value.

	return(0);
}
