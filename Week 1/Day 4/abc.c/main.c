#include <stdio.h>
#include <stdlib.h>

//writing ABC with loop like this : aAbBcC...zZ

int main()
{
        /* ASCII value of a=97 */
    for (int i = 97; i < 122; i++) {

        printf("%c%c\n", i, i-32);

        /*
         %c = ascii code the character. Since we want the first letter in lower case and the second letter same but upper case,
         we need to subtract 32 from "i" because that will change lower case to upper case but the
         same letter.
         */

    }

	return 0;
}
