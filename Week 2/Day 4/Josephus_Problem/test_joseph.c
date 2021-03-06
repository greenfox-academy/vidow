/*
// C program for josephus problem

#include <stdio.h>

// function to find the position of the Most
// Significant Bit
int msbPos(int winning_position)
{
    int pos = 0;
    while (winning_position != 0) {
        pos++;

        // keeps shifting bits to the right
        // until we are left with 0
        winning_position = winning_position >> 1;
    }
    return pos;
}

// function to return at which place Josephus
// should sit to avoid being killed
int joseph(int winning_position)
{
    /*  Getting the position of the Most Significant
        Bit(MSB). The leftmost '1'. If the number is
       '41' then its binary is '101001'.
        So msbPos(41) = 6   */
    int position = msbPos(winning_position);

    /* 'j' stores the number with which to XOR the
        number 'n'. Since we need '100000'
       We will do 1<<6-1 to get '100000' */
    int j = 1 << (position - 1);

    /* Toggling the Most Significant Bit. Changing
       the leftmost '1' to '0'.
       101001 ^ 100000 = 001001 (9) */
    winning_position = winning_position ^ j;

    /*  Left-shifting once to add an extra '0' to
        the right end of the binary number
        001001 = 010010 (18) */
    winning_position = winning_position << 1;

    /* Toggling the '0' at the end to '1' which
       is essentially the same as putting the
       MSB at the rightmost place. 010010 | 1
       = 010011 (19) */
    winning_position = winning_position | 1;

    return winning_position;
}

// hard coded driver main function to run the program
int main()
{
    int winning_position = 0;

    printf("Please enter a number which represents the participants of the game: ");

    scanf("%d", &winning_position);

    printf("You should stand at the place of %d to survive.\n", joseph(winning_position));
    return 0;
}
